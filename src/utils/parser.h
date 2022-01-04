#include <stdlib.h>

size_t strLen(char* string);
char* readInput(void);
char* removeSpaces(char* str, size_t len);
int isCommand(char* str);
enum Commands getCommand(char* buffer, char* cmd);
char* getArgs(char* cmd, char* buffer);
