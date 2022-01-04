CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -O1

main: src/main.c
	$(CC) $(CFLAGS) -o main src/main.c src/utils/builtin.c src/utils/parser.c -lm

clean:
	$(RM) main