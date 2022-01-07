CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99

TARGET = main
TEST = test-suite

MAIN = src/main.o
OBJ = $(patsubst %.c, %.o, $(wildcard src/utils/*.c))
TEST_OBJ = $(patsubst %.c, %.o, $(wildcard tests/*))

HEADERS = $(wildcard src/utils/*.h)
INC_FLAGS = $(addprefix -I, $(dir $(wildcard src/*/)))

CFLAGS += $(INC_FLAGS)

all: release

release: $(TARGET)

debug: CFLAGS += -g -fsanitize=address
debug: LDFLAGS += -fsanitize=address
debug: $(TARGET)

test: CFLAGS += -g -fsanitize=address
test: LDFLAGS += -fsanitize=address -lcriterion
test: $(TEST)
	./$(TEST)

$(TARGET): $(MAIN) $(OBJ)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

$(TEST): $(OBJ) $(TEST_OBJ)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

$(OBJ) $(TEST_OBJ): %.o: %.c $(HEADERS)

.PHONY: clean

clean:
	$(RM) $(TARGET)
	$(RM) $(TEST)
	$(RM) $(MAIN)
	$(RM) $(OBJ)
	$(RM) $(TEST_OBJ)