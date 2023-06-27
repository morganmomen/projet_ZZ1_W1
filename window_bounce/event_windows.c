#include "event_windows.h"


void window_bounce(SDL_Window * window, SDL_Renderer* renderer, int *modx,int *mody, int width, int height)
{
    int *posx = malloc(sizeof(int));
    int *posy = malloc(sizeof(int));
    int *w = malloc(sizeof(int));
    int *h = malloc(sizeof(int));
    //The window will move and bounce on the borders of the screen
    SDL_GetWindowPosition(window,posx,posy);
    SDL_GetWindowSize(window,w,h);    

    if (*posx<=0) 
    {
        *modx=-*modx;
        change_color(renderer);
    }
    if (*posx>=width-*w) 
    {
        *modx=-*modx;
        change_color(renderer);
    }
    if (*posy<=28)
    {
        *mody=-*mody;
        change_color(renderer);
    }
    if (*posy>=height-*h)
    {
        *mody=-*mody;
        change_color(renderer);
    }
    SDL_SetWindowPosition(window,*posx+*modx,*posy+*mody);
    free(posx);
    free(posy);
    free(w);
    free(h);
    SDL_Delay(10);
}

void change_color(SDL_Renderer * renderer)
{
    srand(time(NULL));
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, rand()%255, rand()%255, rand()%255, 255);
    SDL_RenderPresent(renderer);
}
