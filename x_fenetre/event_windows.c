#include "event_windows.h"
#include "windows.h"

void window_movement(SDL_Window * window, int *modx,int *mody, int *posx, int *posy)
{
    switch (*posx)
    {
    case 1920:
        *modx = -*modx;
        SDL_SetWindowPosition(window,*posx+*modx,*posy+*mody);
        break;
    case 0:
        *modx = -*modx;
        SDL_SetWindowPosition(window,*posx+*modx,*posy+*mody);
        break;
    default:
        SDL_SetWindowPosition(window,*posx+*modx,*posy+*mody);
        break;
    }
    switch (*posy)
    {
    case 1080:
        *mody = -*mody;
        SDL_SetWindowPosition(window,*posx+*modx,*posy+*mody);
        break;
    case 0:
        *mody = -*mody;
        SDL_SetWindowPosition(window,*posx+*modx,*posy+*mody);
        break;
    default:
        SDL_SetWindowPosition(window,*posx+*modx,*posy+*mody);
        break;
    }
    SDL_Delay(10);
}