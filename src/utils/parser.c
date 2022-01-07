#include "parser.h"

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
        printf("bshell: allocation error\n");
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
                printf("bshell: allocation error\n");
                return NULL;
            }
        }
    }
    
    return buffer;
}


// REMOVE SPACES
// removes additional spaces in a string and returns a new one
// input: char* string to check
// output: new char* without double/triple/.. spaces
char* removeSpaces(char* str)
{
    size_t len = strlen(str);
    char* new = malloc(sizeof(char) * len);
    size_t i = 0;
    size_t ni = 0;
    int space = 0;

    while (i < len && str[i] != '\0')
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
    if (str[i] != '\0')
        str[i] = '\0';
    return new;
}

struct Tokens getTokens(char* buffer)
{
    size_t len = strlen(buffer);
    buffer = removeSpaces(buffer);

    char **tokens = malloc(len * sizeof(char*));
    char *token = malloc(128 * sizeof(char));
    size_t buffsize = len;
    size_t tokensize = 128;
    size_t i = 0;
    size_t j = 0;
    size_t count = 0;

    if (!tokens) 
    {
        fprintf(stderr, "bshell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (i < len && buffer[i] != '\0')
    {
        if (buffer[i] == ' ')
        {
            tokens[count] = token;
            token = calloc(128, sizeof(char));
            count++;
            j = 0;
            i++;
        }
        else
        {
            token[j] = buffer[i];
            j++;
            i++;
        }       

        if (count >= buffsize) 
        {
            buffsize += 100;
            tokens = realloc(tokens, buffsize * sizeof(char*));
            if (!tokens)
                errx(3, "bshell: allocation error\n");
        }
        if (j >= tokensize)
        {
            tokensize += 100;
            token = realloc(token, tokensize * sizeof(char*));
            if (!token)
                errx(3, "bshell: allocation error\n");
        }
    }

    struct Tokens tok;
    tok.values = tokens;
    tok.length = count;
    //free(tokens);
    //free(token);

    printf("\n");
    for (size_t i = 0; i < tok.length; i++)
    {
        printf("\'%s\' ", tok.values[i]);
    }
    printf("\n");
    return tok;
}

int compareStrings(char* str1, char* str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    if (len1 != len2)
        return 1;
    
    for (size_t i = 0; i < len1; i++)
    {
        if (str1[i] != str2[i])
            return 1;
    }

    return 0;
}


// IS COMMAND
// checks if a string is a command
// input: char* string
// output: int representing the command in enum
enum Commands isCommand(char* str)
{
    int i = 0;
    while (i < NbCommands)
    {
        if (compareStrings(ComStr[i], str) == 0)
            break;
        i++;
    }
    
    switch (i)
    {
        case 0:
            return ECHO;
        case 1:
            return HELP;
        case 2:
            return CLEAR;
        case 3:
            return QUIT;
        case 4:
            return UNKNOWN;
        default:
            return ERROR;
    }
    return ERROR;
}