#ifndef BLOCK_H
#define BLOCK_H

void init_block(Block* block, Shape shape, Uint32 color);
void display_block(Block* block, SDL_Surface* img, SDL_Surface* screen);

#endif
