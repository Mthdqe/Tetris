MAIN_OBJ = main.o
OBJS = play.o block.o read.o grid.o
CFLAGS = -Wall -Wextra -std=c99 -I$(headers)
LDLIBS = -lSDL
CC = gcc
BIN = tetris


$(BIN):

all:
	$(CC) $(MAIN_OBJ) $(OBJS) $(CFLAGS) $(LDLIBS) -o $(BIN)

add_debug_flags:
	CFLAGS += -g -fsanitize=adress

check: add_debug_flags $(BIN)

.PHONY: clean
clean:
	$(RM) $(MAIN_OBJ) $(OBJS) $(BIN)

