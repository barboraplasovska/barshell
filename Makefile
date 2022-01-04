CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -O1

main: src/main.c
	$(CC) $(CFLAGS) -o src/main src/main.c src/utils/builtin.c src/utils/parser.c -lm

builtin.o: src/utils/builtin.c
	$(CC) $(CFLAGS) -c src/utils/builtin.c

parser.o: src/utils/parser.c
	$(CC) $(CFLAGS) -c src/utils/parser.c

clean:
	$(RM) src/main
	$(RM) src/%.o
	$(RM) src/utils/%.o