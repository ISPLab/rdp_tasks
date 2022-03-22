
//#include "SsiCommand.h"
//#include "TCPServer.h"
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <array>
#include <stdlib.h>
#include <dlfcn.h>
#define ASIO_STANDALONE7
//#include <asio/thread_pool.hpp>
//#include <asio/post.hpp>
#include <iostream>
#include <string>
#include <json/json.h>
#include "Manager.h"

#include <string>
#include <iostream>
#include <filesystem>


using namespace std;
const int MAX_COMMAND = 1024 * 4;
const int MAX_BUFFER = 1024 * 64;

int main(int argc, char **argv)
{
    char command[MAX_COMMAND];
    char *cmd_argv[32];
    int cmd_argc;
    Manager *sup = new Manager();
      
    std::cout << "War robots v1.1. Enter command [help] or exit" << std::endl;
 
    while (fgets(command, 1024, stdin))
    {
        cmd_argc = sup->get_command(command, cmd_argv);
        if (cmd_argc > 0)
        {
            if (strcmp(cmd_argv[0], "exit") == 0)
            {
                break;
            }
            if (strcmp(cmd_argv[0], "test1000000") == 0)
            {
                string res;
                for(int i=0; i<1000000; i++)
                    {
                        cmd_argv[0] = (char*)"create";
                        cmd_argv[1] = (char*)"singer";
                        cmd_argv[2] = (char*)"aa";
                        res = sup->run_command(3, cmd_argv);
                        cout << i <<" : "<<res << endl;
                    }
                cout << res << std::endl;
            }
            else
            {
                string res = sup->run_command(cmd_argc, cmd_argv);
                cout << res << "\n";
            }
        }
     
    }
    delete sup;

    return 0;
}