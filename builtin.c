#include "builtin.h"

void help()
{
    printf("Welcome to Barunka's shell!\n");
    printf("-----------------------------------\n");
    printf("\nHere is the list of commands that you can execute:\n");

    for (size_t i = 0; i < NbCommands; i++)
    {
        printf("%s\n", ComStr[i]);
    }
    printf("-----------------------------------\n");$
}


