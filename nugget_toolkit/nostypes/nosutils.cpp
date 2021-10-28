#include "nosutils.h"

#include <google/protobuf/text_format.h>
#include <stdio.h>

#include <iomanip>
#include <iostream>
#include <sstream>

#include "include/log.h"
#include "nostypes.h"

using namespace nostypes;

/* Printer methods */
static std::string hexify(std::string const &s) {
  std::stringstream ss("");
  for (auto c : s) {
    ss << std::setw(2) << std::setfill('0') << std::hex << (0xFF & (int)c);
  }
  return ss.str();
}

class BetterByteFieldValuePrinter : public TextFormat::FastFieldValuePrinter {
  void PrintBytes(const std::string &val,
                  TextFormat::BaseTextGenerator *generator) const {
    PrintString(hexify(val), generator);
  }
};

static std::pair<std::string, std::string> printMessagesToString(Message &req,
                                                                 Message &res) {
  std::string reqstr;
  g_NosPrinter.PrintToString(req, &reqstr);
  std::string resstr;
  g_NosPrinter.PrintToString(res, &resstr);
  return std::pair<std::string, std::string>(reqstr, resstr);
}

void nostypes::printNosCommand(std::string app, std::string cmd,
                               Message &request, Message &response) {
  auto [reqstr, resstr] = printMessagesToString(request, response);

  LOG("%s: %s\n{\n", app.c_str(), cmd.c_str());
  LOG("\tIN");
  if (reqstr.size() > 0) {
    LOG("\n\t{\n");
    LOG("%s", reqstr.c_str());
    LOG("\t}\n");
  } else
    LOG(" {}\n");
  LOG("\tOUT");
  if (resstr.size() > 0) {
    LOG("\n\t{\n");
    LOG("%s", resstr.c_str());
    LOG("\t}\n");
  } else
    LOG(" {}\n");

  LOG("}\n");
}

void nostypes::initNosPrinter() {
  g_NosPrinter.SetHideUnknownFields(false);
  g_NosPrinter.SetInitialIndentLevel(6);
  g_NosPrinter.SetDefaultFieldValuePrinter(new BetterByteFieldValuePrinter());
}

/* Find NosApp and NosCmd */

void nostypes::printAppList() {
  for (auto it = g_nosAppsMap.begin(); it != g_nosAppsMap.end(); ++it)
    std::cerr << it->second.name << std::endl;
}
