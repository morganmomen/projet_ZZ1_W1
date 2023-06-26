#include "event_windows.h"
#include "windows.h"

void window_bounce(SDL_Window * window, int *modx,int *mody, int width, int height)
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
    }
    if (*posx>=width-*w)
    {
        *modx=-*modx;
    }
    if (*posy<=28)
    {
        *mody=-*mody;
    }
    if (*posy>=height-*h)
    {
        *mody=-*mody;
    }
    SDL_SetWindowPosition(window,*posx+*modx,*posy+*mody);
    free(posx);
    free(posy);
    free(w);
    free(h);
    SDL_Delay(10);
}