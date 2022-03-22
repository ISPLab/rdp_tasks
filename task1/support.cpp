#include "support.h"
#include <dirent.h>

string support::run_command(int cmd_argc, char **cmd_argv)
{
    DIR *dir;
    struct dirent *ent;
    if (cmd_argc==1)
        cmd_argv[1]= (char*)"./";
    if ((dir = opendir(cmd_argv[1])) != NULL)
    {

        while ((ent = readdir(dir)) != NULL)
        {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
        return "";
    }
    else
    {
        perror("");
        return "EXIT_FAILURE";
    }
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