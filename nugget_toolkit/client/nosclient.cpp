#include <fuzz.h>
#include <keyblob_utils.h>
#include <nosutils.h>
#include <nugget/app/keymaster/keymaster.pb.h>
#include <rop.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;
using namespace nostypes;

void printHelp(char *arg) {
  cerr << "Usage:" << endl;
  cerr << arg << " cmd <task> <command> [json string for command arguments]"
       << std::endl;
  cerr << arg << " keyblob" << std::endl;
  cerr << arg << " fuzz [--verbose|-v]" << std::endl;
  cerr << arg << " reset" << std::endl;
  cerr << arg << " leak <addr> <size>" << std::endl;
  cerr << arg << " leak_old <addr> <size>" << std::endl;
  cerr << arg << " write <addr>" << std::endl;
  cerr << arg << " leak_kb [-k <key name>]" << std::endl;
}

int main(int argc, char *argv[]) {
  int c;
  enum class mode {
    cmd,
    keyblob,
    fuzz,
    reset,
    leak,
    leak_old,
    write,
    leak_kb,
    help,
    none
  };

  mode selected = mode::none;
  bool verbose = false;
  string address, size;

  static unordered_map<string, mode> mode_map{
      {string("cmd"), mode::cmd},        {string("keyblob"), mode::keyblob},
      {string("fuzz"), mode::fuzz},      {string("reset"), mode::reset},
      {string("leak_old"), mode::leak_old},      {string("leak"), mode::leak},
      {string("write"), mode::write},    {string("help"), mode::help},
      {string("leak_kb"), mode::leak_kb}};

  enum class option { verbose, list, key };
  set<option> opt_set;
  static unordered_map<string, option> option_map{
      {string("v"), option::verbose}, {string("verbose"), option::verbose},
      {string("l"), option::list},    {string("list"), option::list},
      {string("k"), option::key},     {string("key"), option::key},

  };

  unsigned int mode_args = 0;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {  // option
      uint16_t s = 1;
      if (argv[i][1] == '-') s++;
      auto option_it = option_map.find(&argv[i][s]);
      if (option_it == option_map.end()) {  // unknown option
        selected = mode::help;
        break;
      }
      opt_set.insert(option_it->second);
    } else {
      if (selected !=
          mode::none) {  // mode already selected, only check options
        mode_args++;     // count remaining args
        continue;
      }

      auto mode_it = mode_map.find(argv[i]);
      if (mode_it == mode_map.end()) {  // unknown mode
        selected = mode::help;
        break;
      }
      selected = mode_it->second;
    }
  }

  switch (selected) {
    case mode::reset:
      reset();
      break;
    case mode::fuzz:
      fuzz(opt_set.find(option::verbose) != opt_set.end());
      break;
    case mode::leak_old: {
      if (mode_args < 2) {
        printHelp(argv[0]);
        break;
      }

      uint32_t addr, size;
      try {
        addr = stoul(argv[2], nullptr, 16);
        size = stoul(argv[3], nullptr, 16);
      } catch (out_of_range e) {
        cerr << "Argument out of range" << endl;
        return 1;
      } catch (invalid_argument e) {
        cerr << "Argument invalid in base 16" << endl;
        return 1;
      }

      return leak_data(addr, size, true);  // reset the chip

      break;
    }
    case mode::leak_kb: {
      KeyblobUtils kbu;

      if (opt_set.find(option::key) != opt_set.end()) {
        if (mode_args < 1) {
          printHelp(argv[0]);
          break;
        }
        return kbu.leakStrongboxKey(argv[3]);
      } else
        return kbu.listStrongboxKeys();

      break;
    }
    case mode::cmd: {
      // Example: nosclient cmd Keymaster AddRngEntropy {\"data\":\"test\"}

      if (mode_args < 2) {
        printHelp(argv[0]);
        break;
      }

      auto app = NosApp::findNosAppByName(argv[2]);
      if (!app) {
        std::cerr << "Wrong app name: " << argv[2] << std::endl;
        std::cerr << "Available apps:" << std::endl;
        printAppList();
        return 1;
      }

      auto cmd = app->findNosCmdByName(argv[3]);
      if (!cmd) {
        std::cerr << "Wrong cmd name: " << argv[3] << std::endl;
        std::cerr << "Available cmds:" << std::endl;
        app->printCmdList();
        return 1;
      }

      return callNosCmd(mode_args == 2 ? nullptr : argv[4], app, cmd);

      break;
    }
    case mode::keyblob: {
      return generate_dump_blob();
      break;
    }
    case mode::leak: {
      if (mode_args < 2) {
        printHelp(argv[0]);
        break;
      }

      uint32_t addr, size;
      try {
        addr = stoul(argv[2], nullptr, 16);
        size = stoul(argv[3], nullptr, 16);
      } catch (out_of_range e) {
        cerr << "Argument out of range" << endl;
        return 1;
      } catch (invalid_argument e) {
        cerr << "Argument invalid in base 16" << endl;
        return 1;
      }

      return leak_data_v2(addr, size, true);

      break;
    }
    case mode::write: {
      if (argc < 3) {
        printHelp(argv[0]);
        break;
      }

      uint32_t addr;
      try {
        addr = stoul(argv[2], nullptr, 16);
      } catch (out_of_range e) {
        cerr << "Argument out of range" << endl;
        return 1;
      } catch (invalid_argument e) {
        cerr << "Argument invalid in base 16" << endl;
        return 1;
      }
      return write_byte(addr);
    }
    case mode::help:
    default:
      printHelp(argv[0]);
      break;
  }

  return 0;
}
