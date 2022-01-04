#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "builtin.h"

// READ INPUT
// reads the user's input
// input: void
// output: char* containing the user's input
//         NULL if an error occured
char* readInput(void)
{
    int bufferSize = 1024;
    int pos = 0;

    // TODO: free the buffer after it is not used anymore
    // idk where for now
    char* buffer = malloc(sizeof(char) * bufferSize);

    if (!buffer) // allocation error
    {
        printf("barshell: allocation error\n");
        return NULL;
    }

    char c;
    while (1)
    {
        c = getchar(); 

        if (c == -1 || c == '\n') // end of the string
        {
            buffer[pos] = '\0';
            return buffer;
        }
        else
        {
            buffer[pos] = c;
        }

        pos++;
        if (pos >= bufferSize)
        {
            bufferSize *= 2;
            buffer = realloc(buffer, bufferSize);
            if (!buffer) // allocation error
            {
                printf("barshell: allocation error\n");
                return NULL;
            }
        }
    }
    
    return buffer;
}


// REMOVE SPACES
// removes additional spaces in a string and returns a new one
// input: char* string to check and it's length
// output: new char* without double/triple/.. spaces
char* removeSpaces(char* str, size_t len)
{
    char* new = malloc(sizeof(char) * len);
    size_t i = 0;
    size_t ni = 0;
    int space = 0;

    while (i < len)
    {
        if (space == 1)
        {
           if (str[i] == ' ')
              i++;
           else
           {
              space = 0;
              new[ni] = str[i];
              i++;
              ni++;
           }
        }
        else
        {
           if (str[i] == ' ')
              space = 1;

           new[ni] = str[i];
           i++;
           ni++;
        }
    }
    return new;
}

// IS COMMAND
// checks if a string is a command
// input: char* string
// output: int representing the command in enum
int isCommand(char* str)
{
    int i = 0;
    while (i < NbCommands)
    {
        printf("\'%s\' == \'%s\' ? \n", ComStr[i], str);
        if (ComStr[i] == str)
            return i;
        i++;
    }
    return i;
}

// GET COMMAND
// gets the command from the input
// input: string containing the users input
// output: Commands enum type of the command
//         NULL if an error occured or no command found
enum Commands getCommand(char* buffer, char* cmd)
{
    size_t i = 0;
    size_t tempI = 0;
    size_t len = strlen(buffer);
    cmd = malloc(sizeof(char) * 10); //a command should not exceed that

    if (!buffer) // allocation error
    {
        printf("barshell: allocation error\n");
        return ERROR;
    }
    while (i < len)
    {
        if (buffer[i] != ' ')
        {
            cmd[tempI] = buffer[i];
            tempI++;
            i++;
        }
    }

    return isCommand(cmd);
}

char* getArgs(char* cmd, char* buffer)
{
    char* new;
    size_t lenCmd = strlen(cmd);
    size_t lenBuf = strlen(buffer);
    new = malloc(sizeof(char) * (lenBuf - lenCmd));

    for (size_t i = lenCmd-1; i < lenBuf; i++)
        new[i-lenCmd-1] = buffer[i];

    return new;
}
