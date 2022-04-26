#include <SDL/SDL.h>
#include <string.h>
#include "../headers/const.h"

void init_block(struct Block* block, SDL_Surface* screen)
{
    enum Shape shape = rand() % 7;
    block->shape = shape;
    block->x = (CELL_W - 1) / 2;
    block->y = 0;

    static int o_shape[4][4] = {
        { 1, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    };

    static int i_shape[4][4] = {
        { 1, 0, 0, 0 },
        { 1, 0, 0, 0 },
        { 1, 0, 0, 0 },
        { 1, 0, 0, 0 }
    };

    static int s_shape[4][4] = {
        { 0, 1, 1, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0 ,0 },
        { 0, 0, 0, 0 }
    };

    static int z_shape[4][4] = {
        { 1, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    };

    static int l_shape[4][4] = {
        { 1, 0, 0, 0 },
        { 1, 0, 0 ,0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 }
    };

    static int j_shape[4][4] = {
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 }
    };

    static int t_shape[4][4] = {
        { 1, 1, 1, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    };

    switch(shape)
    {
        case O:
            block->w = 2;
            block->h = 2;
            block->color = SDL_MapRGB(screen->format, 255, 255, 0);
            memcpy(block->grid, o_shape, sizeof(int) * 16);
            break;

        case I:
            block->w = 1;
            block->h = 4;
            block->color = SDL_MapRGB(screen->format, 0, 255, 255);
            memcpy(block->grid, i_shape, sizeof(int) * 16);
            break;

        case S:
            block->w = 3;
            block->h = 2;
            block->color = SDL_MapRGB(screen->format, 0, 255, 0);
            memcpy(block->grid, s_shape, sizeof(int) * 16);
            break;

        case Z:
            block->w = 3;
            block->h = 2;
            block->color = SDL_MapRGB(screen->format, 255, 0, 0);
            memcpy(block->grid, z_shape, sizeof(int) * 16);
            break;

        case L:
            block->w = 2;
            block->h = 3;
            block->color = SDL_MapRGB(screen->format, 255, 100, 0);
            memcpy(block->grid, l_shape, sizeof(int) * 16);
            break;

        case J:
            block->w = 2;
            block->h = 3;
            block->color = SDL_MapRGB(screen->format, 0, 0, 255);
            memcpy(block->grid, j_shape, sizeof(int) * 16);
            break;

        case T:
            block->w = 3;
            block->h = 2;
            block->color = SDL_MapRGB(screen->format, 255, 0, 255);
            memcpy(block->grid, t_shape, sizeof(int) * 16);
            break;
    }
}

void display_block(struct Block* block, SDL_Surface* img, SDL_Surface* screen)
{
    SDL_Rect coord;

    SDL_FillRect(img, NULL, block->color);

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

int fall_block(struct Block* block, struct Cell grid[][CELL_W])
{
    int fallen = 0;
    size_t i = 0, j = 0, next;

    while (!fallen && i < block->h)
    {
        while (!fallen && j < block->w)
        {
            if (block->grid[i][j])
            {
                next = block->y + i + 1;

                fallen = next == CELL_H || !grid[next][block->x + j].empty;
            }

            j++;
        }

        i++;
        j = 0;
    }

    if (fallen)
    {
        for (i = 0; i < block->h; i++)
        {
            for (j = 0; j < block->w; j++)
            {
                if (block->grid[i][j])
                {
                    grid[block->y + i][block->x + j].empty = 0;
                    grid[block->y + i][block->x + j].color = block->color;
                }
            }
        }
    }

    else
        block->y++;

    return fallen;
}

void move_block(struct Block* block, enum Dir dir, struct Cell grid[][CELL_W])
{
    int move = 1;
    int step = 1;
    size_t i = 0, j = 0, next;

    if (dir == LEFT)
        step = -1;

    while (move && i < block->h)
    {
        while (move && j < block->w)
        {
            if (block->grid[i][j])
            {
                next = block->x + j + step;

                move = next < CELL_W && grid[block->y + i][next].empty;
            }

            j++;
        }

        i++;
        j = 0;
    }

    if (move)
        block->x += step;
}

static void reverse(size_t* a, size_t* b)
{
    size_t temp = *a;
    *a = *b;
    *b = temp;
}

void rotate_block(struct Block* block, struct Cell grid[][CELL_W])
{
    int new[4][4] = {0};
    int rotate = 1;
    size_t i = 0, j = 0;

    j = block->x + block->h - 1;
    rotate = j < CELL_W;

    while (rotate && i < block->h)
    {
        rotate = grid[i + block->y][j].empty;
        i++;
    }

    if (rotate)
    {
        i = block->y + block->w - 1;
        j = 0;
        rotate = i < CELL_H;

        while (rotate && j < block->w)
        {
            rotate = grid[i][j + block->x].empty;
            j++;
        }
    }

    if (rotate)
    {
        for (i = 0; i < block->h; i++)
        {
            for (j = 0; j < block->w; j++)
                new[j][block->h - i - 1 ] = block->grid[i][j];
        }

        reverse(&block->w, &block->h);

        for (i = 0; i < block->h; i++)
        {
            for (j = 0; j < block->w; j++)
                block->grid[i][j] = new[i][j];
        }
    }
}
