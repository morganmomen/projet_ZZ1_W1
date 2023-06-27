#include "../windows.h"
#include "draw.h"


void bounce_rectangle(SDL_Renderer * renderer,SDL_Window *window)
{
    srand(time(NULL));
    int w;
    int h;
    int modx=25;
    int mody=25;
    int posx=1;
    int posy=1;
    while(SDL_TRUE)
    {
        test_closewindows(window,renderer);
        SDL_GetWindowSize(window,&w,&h);
        SDL_RenderClear(renderer);
        if (posx<=0) modx=-modx;
        if (posx>=w-384) modx=-modx;
        if (posy<=0) mody=-mody;
        if (posy>=h-192)mody=-mody;
        posx+=modx;
        posy+=mody;
        draw_rectangle(renderer,posx,posy,384,216);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    } 
}


int main()
{
    SDL_DisplayMode screen;
    SDL_Window *window = new_window(1920, 1080, 100, 100);
    SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(window),&screen);
    SDL_Renderer * renderer = new_renderer(window);
    bounce_rectangle(renderer,window);
    return 0;  
}