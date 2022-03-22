#include "Manager.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <thread>
#include <mutex>    
string Manager::run_command(int cmd_argc, char **cmd_argv)
{
    if (strcmp(cmd_argv[0], "create") == 0)
    {
        if (cmd_argc < 3)
            return "need set robot type and owner";
        auto type = cmd_argv[1];
        auto owner = cmd_argv[2];
        Robo* r;
        if(type=="singer")
            r = new RoboSinger(owner);
        else r = new RoboNarrator(owner); 
        robotes[r->id] = r;
        checkPlan();
        return r->id;
    }
    

    else if (strcmp(cmd_argv[0], "add_owner") == 0)
    {
        if (cmd_argc < 3)
            return "need set robo id and owner";
        string id = cmd_argv[1];
        string owner = cmd_argv[2];
        return "added";
    }
    else if (strcmp(cmd_argv[0], "delete_owner") == 0)
    {
        if (cmd_argc < 3)
            return "need set robo id";
        string id = cmd_argv[1];
        string owner = cmd_argv[2];
        robotes[id]->deleteOwner(owner);
        if (robotes[id]->ownners.size() == 0)
        {
            robotes.erase(id);
            cout << "the robot was deleted" << endl;
        }

        return "deleted";
    }
    else
        return "undefined command";
    return "done";
}
vector<string> vres;
std::mutex mtx; 
int count_clients;
static void pushResult(string res)
{
      mtx.lock();
       
      vres.push_back(res);
      mtx.unlock();
}

string Manager::getResult(std::map<std::string, Robo*>  robos, string task)
{
    map<string, Robo *>::iterator it;

   
    for (it = robos.begin(); it != robos.end(); ++it)
     {
        cout << it->first << " => " << it->second << '\n';
           
        auto client_callback = [](std::string rawJson)
        {
              pushResult(rawJson);
        };
        it->second->longCalculate(task,client_callback);
    }
     return "done";
}

void Manager::checkPlan()
{
    if (/*run*/ robotes.size() == 10)
    {
        auto rs(robotes);
        thread t1(getResult, rs, "task1");
        t1.detach();
    }
}

int Manager::get_command(char *commandline, char **argv)
{
    char special = 0;
    char *s = commandline, *sprv = commandline;
    int count = 0;

    while (*s)
    {
        if (*s == ' ' && !special)
        {
            *s = 0;
            if (*sprv != 0)
            {
                argv[count++] = sprv;
            }
            sprv = s + 1;
        }
        else if (*s == '\"')
        {
            if (special)
            {
                special = 0;
                *s = 0;
            }
            else
            {
                special = *s;
                sprv = s + 1;
            }
        }

        if (*(s + 1) == '\r' || *(s + 1) == '\n')
        {
            *(s + 1) = 0;
        }

        if (*(s + 1) == 0 && *sprv != 0)
        {
            argv[count++] = sprv;
        }
        s++;
    }

    return count;
}

Manager::Manager()
{
}

Manager::~Manager()
{
}