#define TAILLE_MAX 1000
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>



SDL_Window * new_window(int width, int height, int posx, int posy);
SDL_Renderer * new_renderer(SDL_Window *window);
void test_closewindows(SDL_Window * window);
void endSDL(SDL_Window *window, SDL_Renderer *renderer);
