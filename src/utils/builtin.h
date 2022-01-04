#ifndef BUILTIN_H
#define BUILTIN_H

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

int executeCommand(enum Commands command, char* cmd, char* args);
void echo(char* args);
void help(void);
void clear(void);
void unknownCommand(char* c);

#endif