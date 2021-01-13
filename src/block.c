#include <SDL/SDL.h>
#include "../headers/const.h"
#include "../headers/read.h"

void init_block(Block* block, Shape shape, Uint32 color)
{
    block->shape = shape;

    switch(shape)
    {
        case O:
            block->w = 2;
            block->h = 2;
            read(block, "Shapes/o");
            break;

        case I:
            block->w = 1;
            block->h = 4;
            read(block, "Shapes/i");
            break;

        case S:
            block->w = 3;
            block->h = 2;
            read(block, "Shapes/s");
            break;

        case Z:
            block->w = 3;
            block->h = 2;
            read(block, "Shapes/z");
            break;

        case L:
            block->w = 2;
            block->h = 3;
            read(block, "Shapes/l");
            break;

        case J:
            block->w = 2;
            block->h = 3;
            read(block, "Shapes/j");
            break;

        case T:
            block->w = 3;
            block->h = 2;
            read(block, "Shapes/t");
            break;
    }

    block->x = 0;
    block->y = 0;
    block->color = color;
}

void display_block(Block* block, SDL_Surface* img, SDL_Surface* screen)
{
    SDL_Rect coord = {1, 1, CELL - 2, CELL-2};

    SDL_FillRect(img, &coord, block->color);

    for (size_t i = 0; i < block->h; i++)
    {
        for (size_t j = 0; j < block->w; j++)
        {
            if (block->grid[i][j])
            {
                coord.x = (block->x + j) * CELL;
                coord.y = (block->y + i) * CELL;
                SDL_BlitSurface(img, NULL, screen, &coord);
            }
        }
    }
}
