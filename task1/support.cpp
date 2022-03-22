#include "support.h"
#include <dirent.h>


string support::run_command(int cmd_argc, char **cmd_argv)
{
    if( strcmp(cmd_argv[0], "ls") == 0)
    {
       DIR *dir;
            struct dirent *ent;
            if ((dir = opendir("./")) != NULL)
            {
                /* print all the files and directories within directory */
                while ((ent = readdir(dir)) != NULL)
                {
                    printf("%s\n", ent->d_name);
                }
                closedir(dir);
                return "done";
            }
            else
            {
                /* could not open directory */
                perror("");
                return "EXIT_FAILURE";
            }
    }
    else return "undefined command";
}


int support::get_command(char *commandline, char **argv)
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

support::support()
{
   
}

support::~support()
{
   
}