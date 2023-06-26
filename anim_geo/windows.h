#define TAILLE_MAX 1000
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>



SDL_Window * new_window(int width, int height, int posx, int posy);
void destroy_windows(SDL_Window *window);
