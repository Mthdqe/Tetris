#include <SDL/SDL.h>
#include <time.h>
#include "../headers/const.h"
#include "../headers/block.h"
#include "../headers/grid.h"

void play(SDL_Surface* screen)
{
    int leave = 0;
    int ticks, fallTime = 0, moveTime = 0, rotateTime = 0;
    int fall_freq = FALL_FREQ, fall_freq_atm = FALL_FREQ;
    int score = 0;
    int partial_score = 0;
    SDL_Event event;
    Uint32 bgColor = SDL_MapRGB(screen->format, 30, 30, 30);
    SDL_Surface* img = SDL_CreateRGBSurface(SDL_HWSURFACE, CELL - 2, CELL - 2, 32, 0, 0, 0, 0);
    struct Block* block = malloc(sizeof(struct Block));
    struct Cell grid[CELL_H][CELL_W];
    enum Dir dir = NONE;

    srand(time(NULL));

    init_block(block, screen);
    init_grid(grid);

    while (!leave)
    {
        dir = NONE;
        fall_freq = fall_freq_atm;

        SDL_PollEvent(&event);

        ticks = SDL_GetTicks();

        if (event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    leave = 1;
                    break;

                case SDLK_LEFT:
                    dir = LEFT;
                    break;

                case SDLK_RIGHT:
                    dir = RIGHT;
                    break;

                case SDLK_DOWN:
                    fall_freq /= 5;
                    break;

                case SDLK_UP:
                    if (ticks - rotateTime >= MOVE_FREQ)
                    {
                        rotate_block(block, grid);
                        rotateTime = ticks;
                    }
                    break;

                default:
                    break;
            }
        }

        if (dir != NONE && ticks - moveTime >= MOVE_FREQ)
        {
            move_block(block, dir, grid);
            moveTime = ticks;
        }

        if (ticks - fallTime >= fall_freq)
        {
            if (fall_block(block, grid))
            {
                leave = check_lose(grid);
                if (!leave)
                {
                    partial_score = check_lines(grid);
                    score += partial_score;
                    init_block(block, screen);

                    if (fall_freq_atm > FALL_FREQ_LIMIT)
                    {
                        fall_freq_atm -= 20 * partial_score;
                        if (fall_freq_atm < FALL_FREQ_LIMIT)
                            fall_freq_atm = FALL_FREQ_LIMIT;
                    }
                }
            }

            fallTime = ticks;
        }

        SDL_FillRect(screen, NULL, bgColor);

        display_block(block, img, screen);
        display_grid(grid, img, screen);

        SDL_FillRect(img, NULL, bgColor);
        SDL_Flip(screen);
    }

    free(block);
    SDL_FreeSurface(img);
    printf("Score: %d\n", score);
}
