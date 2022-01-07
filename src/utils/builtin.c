#include "builtin.h"

// EXECUTE COMMAND
// executes the appropriate command
int executeCommand(enum Commands command,struct Tokens args)
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
               unknownCommand(args.values[0]);
               break;
       }
    }
    return 0;
}

// ECHO
// prints out the arguments into the standart output
// usage: echo text text
void echo(struct Tokens args)
{
    if (args.length == 1)
        printf("\n\n");
    else
    {
        for (size_t i = 1; i < args.length; i++)
            printf("%s ", args.values[i]);
        printf("\n");
    }
}

// HELP
// prints out all the possible commands
// usage: help
void help(void)
{
    printf("Welcome to Barunka's shell!\n");
    printf("\n-----------------------------------\n");
    printf("Here is the list of commands that you can execute:\n");

    for (int i = 0; i < NbCommands; i++)
    {
        printf("%s --> %s\n", ComStr[i], Usage[i]);
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
    printf("bshell: command not found: %s\n", c);
}
