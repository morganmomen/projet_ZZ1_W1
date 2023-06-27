#include "windows.h"


void draw_rectangle(SDL_Renderer * renderer,SDL_Window *window, int x, int y)
{
    int w_width, w_height;
    SDL_GetWindowSize(window, &w_width, &w_height);
    SDL_Rect rect = {x,y,384,196};
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);    
}

void bounce_rectangle(SDL_Renderer * renderer,SDL_Window *window)
{
    int *posx = malloc(sizeof(int));
    int *posy = malloc(sizeof(int));
    int *w = malloc(sizeof(int));
    int *h = malloc(sizeof(int));
    int modx=1;
    int mody=1;
    *posx=0;
    *posy=0;
    SDL_GetWindowPosition(window,posx,posy);
    SDL_GetWindowSize(window,w,h);
    while(SDL_TRUE)
    {
        if (*posx<=0) modx=-modx;
        if (*posx>=*w-300) modx=-modx;
        if (*posy<=0) mody=-mody;
        if (*posy>=*h-300)mody=-mody;
        draw_rectangle(renderer,window,*posx+modx,*posy+mody);
        SDL_Delay(10);
    }
    
}


int main()
{
    SDL_DisplayMode screen;
    SDL_Window *window = new_window(1000, 600, 100, 100);
    SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(window),&screen);
    SDL_Renderer * renderer = new_renderer(window);
    //Dessin dans le renderer
    bounce_rectangle(renderer,window);
    clear_renderer(renderer);
    destroy_windows(window);
    
}