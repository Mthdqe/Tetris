#ifndef BLOCK_H
#define BLOCK_H

void init_block(Block* block, SDL_Surface* screen);
void display_block(Block* block, SDL_Surface* img, SDL_Surface* screen);
int fall_block(Block* block, Cell grid[][CELL_W]);
void move_block(Block* block, Dir dir, Cell grid[][CELL_W]);
void rotate_block(Block* block, Cell grid[][CELL_W]);

#endif
