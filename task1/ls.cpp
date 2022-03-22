
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
#include "support.h"

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
    support *sup = new support();

    std::cout << "ls v1.1. Enter command: ls or exit" << std::endl;

    /*  std::string path = "/path/to/directory";
    for (const auto & entry : std::filesystem::directory_iterator(path))
        std::cout << entry.path() << std::endl;*/

    while (fgets(command, 1024, stdin))
    {
        cmd_argc = sup->get_command(command, cmd_argv);
        if (cmd_argc > 0)
        {
            if (strcmp(cmd_argv[0], "exit") == 0)
            {
                break;
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