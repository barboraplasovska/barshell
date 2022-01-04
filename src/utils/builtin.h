#define NbCommands 5

enum Commands
{
    ECHO,
    HELP,
    CLEAR,
    QUIT,
    UNKNOWN,
    ERROR
};

char ComStr[4][6] = {"echo", "help", "clear", "quit"};

int executeCommand(enum Commands command, char* cmd, char* args);
void echo(char* args);
void help(void);
void clear(void);
void unknownCommand(char* c);
