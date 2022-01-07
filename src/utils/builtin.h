#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "../models/tokens.h"

#define NbCommands 4

enum Commands
{
    ECHO,
    HELP,
    CLEAR,
    QUIT,
    UNKNOWN,
    ERROR
};

static char* ComStr[] = {"echo", "help", "clear", "quit"};

static char* Usage[] = 
    {
        "echo [string ...]",
        "help",
        "clear",
        "quit"
    };

int executeCommand(enum Commands command, struct Tokens args);
void echo(struct Tokens args);
void help(void);
void clear(void);
void unknownCommand(char* c);

#endif