#include "builtin.h"

void help(void)
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

void clear(void)
{
    printf("\e[1;1H\e[2J");
}


