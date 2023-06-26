#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Erreur SDL_Init : - %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    while (cond)
    {
        /* code */
    }
    
}

