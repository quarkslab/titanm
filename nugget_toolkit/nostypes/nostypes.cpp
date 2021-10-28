#include "nostypes.h"

#include "nugget/app/avb/avb.pb.h"
#include "nugget/app/identity/identity.pb.h"
#include "nugget/app/keymaster/keymaster.pb.h"
#include "nugget/app/weaver/weaver.pb.h"

using namespace nostypes;
using namespace std;

/* Commands declarations */
NosCmd::NosCmd() {
  this->id = -1;
  this->name = "";
  this->request = nullptr;
  this->reply = nullptr;
}

NosCmd::NosCmd(int id, string name, Message *request, Message *reply) {
  this->id = id;
  this->name = name;
  this->request = request;
  this->reply = reply;
}

bool NosCmd::isNameSame(string name) const { return this->name == name; }

/* App declarations */
NosApp::NosApp(int id, string name, std::map<int, NosCmd> cmds) {
  this->id = id;
  this->name = name;
  this->cmds = cmds;
}

bool NosApp::isNameSame(string name) const { return this->name == name; }

const NosCmd *NosApp::findNosCmdByName(string name) const {
  for (auto it = this->cmds.begin(); it != this->cmds.end(); ++it)
    if (it->second.isNameSame(name)) return &it->second;
  return NULL;
}

const NosApp *NosApp::findNosAppByName(string name) {
  for (auto it = g_nosAppsMap.begin(); it != g_nosAppsMap.end(); ++it)
    if (it->second.isNameSame(name)) return &it->second;
  return NULL;
}

void NosApp::printCmdList() const {
  for (auto it = this->cmds.begin(); it != this->cmds.end(); ++it)
    std::cerr << it->second.name << endl;
}
