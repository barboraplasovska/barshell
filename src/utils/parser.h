#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include "builtin.h"
#include "../models/tokens.h"


char* readInput(void);
char* removeSpaces(char* str);
int compareStrings(char* str1, char* str2);
struct Tokens getTokens(char* buffer);
enum Commands isCommand(char* arg);

#endif