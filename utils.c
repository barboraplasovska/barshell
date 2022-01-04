#include "utils.h"
#include "builtin.h"

void executeCommand(char* argv)
{
    
}

void run()
{

}

char* readInput()
{
    int bufferSize = 1024;
    int pos = 0;
    char* buffer = malloc(size_of(char) * bufferSize);

    if (!buffer) // allocation error
        printf("barshell: allocation error\n");
    else
    {
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

            }
        }
    }
}


