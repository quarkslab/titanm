#include <fuzz.h>
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

void printHelp(char *arg) {
  cerr << "Usage:" << endl;
  cerr << arg << " cmd [command arguments]" << std::endl;
  cerr << arg << " keyblob" << std::endl;
  cerr << arg << " fuzz [--verbose|-v]" << std::endl;
  cerr << arg << " reset" << std::endl;
  cerr << arg << " leak <addr> <size>" << std::endl;
}

int main(int argc, char *argv[]) {
  int c;
  enum class mode { cmd, keyblob, fuzz, reset, leak, help, none };

  mode selected = mode::none;
  bool verbose = false;
  string address, size;

  static unordered_map<string, mode> mode_map{
      {string("cmd"), mode::cmd},   {string("keyblob"), mode::keyblob},
      {string("fuzz"), mode::fuzz}, {string("reset"), mode::reset},
      {string("leak"), mode::leak}, {string("help"), mode::help}};

  enum class option { verbose };
  set<option> opt_set;
  static unordered_map<string, option> option_map{
      {string("v"), option::verbose},
      {string("verbose"), option::verbose},
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
    case mode::leak: {
      if (mode_args < 2) {
        printHelp(argv[0]);
        break;
      }

      // TODO: handle strtol errors
      return leak_data(strtol(argv[2], nullptr, 16),
                       strtol(argv[3], nullptr, 16));

      break;
    }
    case mode::cmd: {
      cout << "cmd" << endl;
      break;
    }
    case mode::keyblob: {
      return generate_dump_blob();
      break;
    }
    case mode::help:
    default:
      printHelp(argv[0]);
      break;
  }

  return 0;
}
