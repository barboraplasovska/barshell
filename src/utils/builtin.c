#include <stdlib.h>
#include <stdio.h>
#include "builtin.h"

// EXECUTE COMMAND
// executes the appropriate command
int executeCommand(enum Commands command, char* cmd, char* args)
{
    if (command == QUIT)
       return 1;
    else
    {
       switch (command)
       {
           case ECHO:
               echo(args);
               break;
           case CLEAR:
               clear();
               break;
           case HELP:
               help();
               break;
           default:
               unknownCommand(cmd);
               break;
       }
    }
    return 0;
}

// ECHO
// prints out the arguments into the standart output
// usage: echo text text
void echo(char* args)
{
    printf("%s", args);
}

// HELP
// prints out all the possible commands
// usage: help
void help(void)
{
    printf("Welcome to Barunka's shell!\n");
    printf("-----------------------------------\n");
    printf("\nHere is the list of commands that you can execute:\n");

    for (size_t i = 0; i < NbCommands; i++)
    {
        printf("%s\n", ComStr[i]);
    }
    printf("-----------------------------------\n");
}

// CLEAR
// clears the "Terminal"
// usage: clear
void clear(void)
{
    printf("\e[1;1H\e[2J");
}

void unknownCommand(char* c)
{
    printf("barshell: %s: unknown command\n", c);
}
