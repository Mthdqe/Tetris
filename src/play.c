#include <SDL/SDL.h>
#include "../headers/const.h"
#include "../headers/block.h"

void play(SDL_Surface* screen)
{
    int leave = 0;
    SDL_Event event;

    Uint32 bgColor = SDL_MapRGB(screen->format, 30, 30, 30);
    Uint32 blue = SDL_MapRGB(screen->format, 0, 128, 255);

    SDL_Surface* img = SDL_CreateRGBSurface(SDL_HWSURFACE, CELL, CELL, 32, 0, 0, 0, 0);

    Block* block = malloc(sizeof(struct Block));
    init_block(block, T, blue);

    while (!leave)
    {
        SDL_WaitEvent(&event);

        if (event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    leave = 1;
                    break;

                default:
                    break;
            }
        }

        SDL_FillRect(screen, NULL, bgColor);
        display_block(block, img, screen);
        SDL_Flip(screen);
    }

    free(block);
    SDL_FreeSurface(img);
}
