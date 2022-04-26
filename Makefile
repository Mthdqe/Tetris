CC = gcc
OBJS = src/block.o src/grid.o src/main.o src/play.o src/read.o
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -Iheaders
DFLAGS =
LDLIBS = -lSDL
BIN = tetris

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $^ $(CFLAGS) $(DFLAGS) $(LDLIBS) -o $@

check: CFLAGS += -g -fsanitize=address
check: $(BIN)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(BIN)

