SRC = src/main.c src/play.c src/block.c src/read.c
CFLAGS = -Wall -Wextra -std=c99 -fsanitize=address
FLAGS = -lSDL
BIN = tetris

all:
	gcc $(SRC) $(FLAGS) $(CFLAGS) -o $(BIN)

clean:
	rm $(BIN)
