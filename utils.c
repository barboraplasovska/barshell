#include "utils.h"
#include "builtin.h"

void executeCommand(char* argv)
{
    
}

void run()
{

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
    char* buffer = malloc(size_of(char) * bufferSize);

    if (!buffer) // allocation error
    {
        printf("barshell: allocation error\n");
        return NULL;
    }
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
                buffer = realloc(buffer, bufferSize);
                if (!buffer) // allocation error
                {
                    printf("barshell: allocation error\n");
                    return NULL;
                }
            }
        }
    }
    return buffer;
}


