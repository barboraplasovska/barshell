#include "utils.h"
#include "builtin.h"

void run()
{
    int status = 0;

    while(status == 0)
    {
        printf("$ ");
        char* userInput = readInput();
        Commands com = getCommand(userInput);
        if (com != NULL)
            status = executeCommand(com);
    }
}

int executeCommand(Commands command, char* args)
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
           case CAT:
               cat(args);
               break;
           case CLEAR:
               clear();
               break;
           case HELP:
               help();
               break;
           default:
               unknownCommand();
               break;
       }
    }
    return 0;
}




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
    char* buffer = malloc(size_of(char) * bufferSize);

    if (!buffer) // allocation error
    {
        printf("barshell: allocation error\n");
        return NULL;
    }
    char c;
    while (true)
    {
        c = scanf("%c", &c);

        if (c == EOF) // end of the string
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

size_t strlen(char* string)
{
    size_t len = 0;
    while (string[len])
        len++;
    return len;
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
Commands getCommand(char* buffer)
{
    size_t i = 0;
    size_t tempI = 0;
    size_t len = strlen(buffer);
    Commands c = NULL;
    char* temp = malloc(size_of(char) * 10); //a command should not exceed that

    if (!buffer) // allocation error
    {
        printf("barshell: allocation error\n");
        return NULL;
    }
    while (i < len && !c)
    {
        if (buffer[i] == ' ')
            tempI++;
        else
        {
            temp[tempI] = buffer[i];
        }

        c = isCommand(temp);
        if (c != NULL)
            return c;
        tempI++;
        i++;
    }
}
