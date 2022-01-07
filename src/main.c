#include "main.h"

// MAIN ROUTINE
int main(void)
{
    int status = 0;

    while(status == 0)
    {
        printf("bshell$ ");
        char* buffer = readInput();
        if (buffer[0] != '\0')
        {
            struct Tokens args;
            args = getTokens(buffer);
            enum Commands command = isCommand(args.values[0]);
            if (command != ERROR)
            {
                status = executeCommand(command, args);
            }
            else
                errx(2, "Bshell : command ERROR");
        }
    }
    
    return 0;
}
