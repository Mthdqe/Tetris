#include <SDL/SDL.h>
#include <unistd.h>
#include "../headers/const.h"

void init_grid(struct Cell grid[][CELL_W])
{
    for (size_t i = 0; i < CELL_H; i++)
    {
        for (size_t j = 0; j < CELL_W; j++)
        {
            struct Cell c = {1, 0};
            grid[i][j] = c;
        }
    }
}

void display_grid(struct Cell grid[][CELL_W], SDL_Surface* img, SDL_Surface* screen)
{
    SDL_Rect coord;

    for (size_t i = 0; i < CELL_H; i++)
    {
        for (size_t j = 0; j < CELL_W; j++)
        {
            if (!grid[i][j].empty)
            {
                SDL_FillRect(img, NULL, grid[i][j].color);

                coord.x = j * CELL;
                coord.y = i * CELL; 
                SDL_BlitSurface(img, NULL, screen, &coord);
            }
        }
    }
}

static void drop_grid(struct Cell grid[][CELL_W], size_t index)
{
    for (size_t i = index; i > 0; i--)
    {
        for (size_t j = 0; j < CELL_W; j++)
            grid[i][j] = grid[i-1][j];
    }
}

size_t check_lines(struct Cell grid[][CELL_W])
{
    size_t score = 0;

    for (size_t i = 1; i < CELL_H; i++)
    {
        size_t j = 0;

        while (j < CELL_W && !grid[i][j].empty)
            j++;

        if (j == CELL_W)
        {
            drop_grid(grid, i);
            score += 1;
        }
    }

    return score;
}

int check_lose(struct Cell grid[][CELL_W])
{
    size_t j = 0;

    while (j < CELL_W && grid[0][j].empty)
        j++;

    return j != CELL_W;
}
