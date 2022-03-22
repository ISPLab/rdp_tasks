#pragma once
#include <string>
#include <functional>
#include <iostream>
#include <vector>

#include <stdio.h>
#include <string.h>

using namespace std;
class support
{
private:
public:
  support();
  string run_command(int cmd_argc, char **cmd_argv);
  int get_command(char *commandline, char **argv);
  ~support();
};
