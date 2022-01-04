#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "utils/parser.h"
#include "utils/builtin.h"

// MAIN ROUTINE
int main(void)
{
    int status = 0;

    while(status == 0)
    {
        printf("bshell$ ");
        char* buffer = readInput();
        //
        //printf("\nread input\n");

        char* cmd = NULL;
        enum Commands com = getCommand(buffer, cmd);

        char* args = getArgs(cmd, buffer);
        if (com != ERROR)
        {
            status = executeCommand(com, cmd, args);
        }
    }
    
    return 0;
}
