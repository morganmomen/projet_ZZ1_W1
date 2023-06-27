#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"

SDL_Window * new_window(int width, int height, int posx, int posy)
{
    SDL_Window *window = NULL;
        /* Initialisation de la SDL  + gestion de l'échec possible */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Error : SDL initialisation - %s\n", 
                SDL_GetError());                // l'initialisation de la SDL a échoué 
    exit(EXIT_FAILURE);
    }
    window = SDL_CreateWindow("BND",posx, posy,width, height,SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
    SDL_Log("Error : SDL window 1 creation - %s\n", 
                SDL_GetError());                 // échec de la création de la fenêtre
    SDL_Quit();                              // On referme la SDL       
    exit(EXIT_FAILURE);
    }
    SDL_Delay(100);
    return window;
}

SDL_Renderer * new_renderer(SDL_Window *window)
{
    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
    SDL_Log("Error : SDL renderer creation - %s\n", 
                SDL_GetError());                 // échec de la création de la fenêtre
    SDL_Quit();                              // On referme la SDL       
    exit(EXIT_FAILURE);
    }
    SDL_Delay(100);
    return renderer;
}


void test_closewindows(SDL_Window * window, SDL_Renderer * renderer)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                endSDL(window, renderer);
                exit(EXIT_SUCCESS);
                break;
            }
            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    {
                        endSDL(window, renderer);
                        exit(EXIT_SUCCESS);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
            default:
            {
                break;
            }
        }
    }
}
void endSDL(SDL_Window * window, SDL_Renderer * renderer)
{
    if (renderer != NULL) 
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    if (window != NULL)
    {                                           
        SDL_DestroyWindow(window);
        window= NULL;
    }
    SDL_Quit();
    exit(EXIT_SUCCESS);
}