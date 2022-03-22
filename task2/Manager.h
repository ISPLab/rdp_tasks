#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <stdio.h>
#include <string.h>
#include "robo.h"
#include <dirent.h>
#include <map>
using namespace std;
class Manager
{
private:

static string getResult(std::map<std::string, Robo*>  robos, string task);
public:
  std::map<std::string, Robo*> robotes ;
  //vector<Robo*> robotes;
  Manager();
  string run_command(int cmd_argc, char **cmd_argv);
  int get_command(char *commandline, char **argv);
  void checkPlan();
  ~Manager();
};
