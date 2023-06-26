#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void new_window(int width, int height, int posx, int posy)
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
    SDL_Delay(10000);
    SDL_DestroyWindow(window);
}