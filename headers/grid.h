#ifndef GRID_H
#define GRID_H

#include <unistd.h>

void init_grid(struct Cell grid[][CELL_W]);
void display_grid(struct Cell grid[][CELL_W], SDL_Surface* img, SDL_Surface* screen);
size_t check_lines(struct Cell grid[][CELL_W]);
int check_lose(struct Cell grid[][CELL_W]);

#endif
