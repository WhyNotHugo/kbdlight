#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void usage() {
    cout << "Usage: kbdlight [up|down|off|max|get|set <value>]" <<endl;
    exit(0);
}

int main(int argc, char* argv[]) {
  const string bl_base_path  = "/sys/class/leds/smc::kbd_backlight";
  const string bl_value_file = bl_base_path + "/brightness";
  const string bl_max_file   = bl_base_path + "/max_brightness";

  int current, next, maxval;

  if (argc < 2)
    usage();

  ifstream ifile(bl_value_file.c_str());

  if (ifile) {
    ifile >> current;
    ifile.close();
  } else {
    cerr << "failed to open the keyboard backlight file: " << bl_value_file;
    return 1;
  }

  ifile.open(bl_max_file.c_str());

  if(ifile) {
    ifile >> maxval;
    ifile.close();
  } else {
    maxval = 255;
  }

  string cmd = string(argv[1]);

  if (!cmd.compare("up"))
    next = current >= maxval-16 ? maxval : current + 16;
  else if (!cmd.compare("down"))
    next = current <= 16 ? 0 : current - 16;
  else if (!cmd.compare("off"))
    next = 0;
  else if (!cmd.compare("max"))
    next = 255;
  else if (!cmd.compare("set")) {
    char *endp;
    if(!argv[2] || (next = strtol(argv[2], &endp, 10), endp == argv[2])) {
      cerr << "set must be followed by a number from 0 to "<< maxval << endl;
      return 1;
    }
  } else if(!cmd.compare("get")) {
    cout << current;
    return 0;
  } else {
    usage();
    return 1;
  }

  ofstream ofile(bl_value_file.c_str());
  if(ofile) {
    ofile << next;
    ofile.close();
  } else {
    cerr << "failed to write to the keyboard backlight file: " << bl_value_file;
  }

  return 0;
}
