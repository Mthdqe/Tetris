SRC = src/main.c src/play.c src/block.c src/read.c src/grid.c
CFLAGS = -Wall -Wextra -std=c99 -g -fsanitize=address
FLAGS = -lSDL
BIN = tetris

all:
	gcc $(SRC) $(FLAGS) $(CFLAGS) -o $(BIN)

clean:
	rm $(BIN)
