#include parser.h

char* removeSpaces(char* str, size_t len)
{
    char* new = malloc(size_t(char) * len);
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
}
