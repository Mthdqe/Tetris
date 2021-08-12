#ifndef GRID_H
#define GRID_H

#include <unistd.h>

void init_grid(Cell grid[][CELL_W]);
void display_grid(Cell grid[][CELL_W], SDL_Surface* img, SDL_Surface* screen);
size_t check_lines(Cell grid[][CELL_W]);
int check_lose(Cell grid[][CELL_W]);

#endif
