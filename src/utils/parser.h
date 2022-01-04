#ifndef PARSER_H
#define PARSER_H
#include <stdlib.h>

char* readInput(void);
char* removeSpaces(char* str, size_t len);
int isCommand(char* str);
enum Commands getCommand(char* buffer, char* cmd);
char* getArgs(char* cmd, char* buffer);

#endif