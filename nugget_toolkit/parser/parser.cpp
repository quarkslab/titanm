#include <include/log.h>
#include <nostypes.h>
#include <nosutils.h>

#include <iomanip>
#include <iostream>
#include <sstream>

#include "nugget/app/avb/avb.pb.h"
#include "nugget/app/identity/identity.pb.h"
#include "nugget/app/keymaster/keymaster.pb.h"
#include "nugget/app/weaver/weaver.pb.h"

using namespace std;
using namespace google::protobuf;
using namespace nostypes;

void nugget_parser(uint param, char *request, uint32_t request_size,
                   char *reply, uint32_t reply_size);

void parseNosCommand(uint32_t appId, uint32_t cmdId, char *request,
                     uint32_t request_size, char *reply, uint32_t reply_size) {
  auto appit = g_nosAppsMap.find(appId);
  if (appit == g_nosAppsMap.end()) {
    if (appId == 0) {  // specific case of Nugget App
      nugget_parser(cmdId, request, request_size, reply, reply_size);
      return;
    }

    LOG("App ID not handled 0x%x cmd 0x%x\n", appId, cmdId);
    return;
  }
  auto app = appit->second;
  auto cmdit = app.cmds.find(cmdId);
  if (cmdit == app.cmds.end()) {
    LOG("Cmd ID 0x%x not handled for app %s\n", cmdId, app.name.c_str());
    return;
  }

  auto cmd = cmdit->second;

  string request_data(request, request_size);
  string reply_data(reply, reply_size);

  cmd.request->ParseFromString(request_data);
  cmd.reply->ParseFromString(reply_data);

  printNosCommand(app.name, cmd.name, *cmd.request, *cmd.reply);
}

int sanity_check() {
  LOG("Hello from the other side");
  return 42;
}

void nugget_parser(uint32_t param, char *request, uint32_t request_size,
                   char *reply, uint32_t reply_size) {
  switch (param) {
    case 0x0:
      LOG("Nugget: get_img_info\n{\n\tOUT { %s }\n}\n", reply);
      break;
    case 0xd:
      LOG("Nugget: handle_ap_uart_passthr\n{\n");
      if (request_size > 0) LOG("\trequest=%x\n", request[0]);
      LOG("\treply=%x\n}\n", reply[0]);
      break;
    case 0x10:
      LOG("Nugget: get_event_record\n{");
      LOG("}\n");
      break;
    case 0x200:
      LOG("Nugget: get_low_power_stats\n{");
      LOG("}\n");
      break;
    default:
      LOG("Nugget: No handler yet for function #%d\n", param);
      break;
  }
}

extern "C" void parser(uint app_id, uint param, char *request,
                       uint32_t request_size, char *reply, uint32_t reply_size);

void parser(uint app_id, uint param, char *request, uint32_t request_size,
            char *reply, uint32_t reply_size) {
  initNosPrinter();

  parseNosCommand(app_id, param, request, request_size, reply, reply_size);
}
