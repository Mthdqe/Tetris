#ifndef BLOCK_H
#define BLOCK_H

void init_block(struct Block* block, SDL_Surface* screen);
void display_block(struct Block* block, SDL_Surface* img, SDL_Surface* screen);
int fall_block(struct Block* block, struct Cell grid[][CELL_W]);
void move_block(struct Block* block, enum Dir dir, struct Cell grid[][CELL_W]);
void rotate_block(struct Block* block, struct Cell grid[][CELL_W]);

#endif
