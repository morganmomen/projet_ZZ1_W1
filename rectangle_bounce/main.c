#include "../windows.h"
#include "draw.h"
#include <time.h>




void bounce_rectangle(SDL_Renderer * renderer,SDL_Window *window)
{
    int *posx = malloc(sizeof(int));
    int *posy = malloc(sizeof(int));
    int *w = malloc(sizeof(int));
    int *h = malloc(sizeof(int));
    int modx=25;
    int mody=25;
    *posx=1;
    *posy=1;
    while(SDL_TRUE)
    {
        SDL_GetWindowSize(window,w,h);
        SDL_RenderClear(renderer);
        if (*posx<=0) modx=-modx;
        if (*posx>=*w-384) modx=-modx;
        if (*posy<=0) mody=-mody;
        if (*posy>=*h-192)mody=-mody;
        *posx+=modx;
        *posy+=mody;
        test_closewindows(window);
        draw_rectangle(renderer,*posx,*posy,384,216);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    free(posx);
    free(posy);
    free(w);
    free(h);    
}


int main()
{
    SDL_DisplayMode screen;
    SDL_Window *window = new_window(1920, 1080, 100, 100);
    SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(window),&screen);
    SDL_Renderer * renderer = new_renderer(window);
    //Dessin dans le renderer
    bounce_rectangle(renderer,window);
    destroy_windows(window);
    
}