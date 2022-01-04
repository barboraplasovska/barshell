
DEFINE NbCommands 5

enum Commands
{
    ECHO,
    CAT,
    HELP,
    CLEAR,
    QUIT,
    UNKNOWN
};

char* ComStr =
{
    "echo",
    "cat",
    "help",
    "clear",
    "quit"
};

void help(void);
void clear(void);
