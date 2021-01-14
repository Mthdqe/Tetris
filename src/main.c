#include <SDL/SDL.h>
#include <time.h>
#include "../headers/const.h"
#include "../headers/play.h"

int main()
{
    SDL_Surface* screen = NULL;
    time_t t;

    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(WINDOW_W, WINDOW_H, 32, SDL_HWSURFACE);

    srand((unsigned) time(&t));
    play(screen);

    SDL_FreeSurface(screen);
    //SDL_Quit();

    return 0;
}
