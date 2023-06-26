#include "windows.h"


void voiture(SDL_Renderer * renderer,SDL_Window *window)
{
    int w_width, w_height;
    SDL_GetWindowSize(window, &w_width, &w_height);
    SDL_Rect rect = {w_width/2-300,w_height-150,300,100};
    SDL_Rect roue1 = {w_width/2-300,w_height-50,50,50};
    SDL_Rect roue2 = {w_width/2-50,w_height-50,50,50};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &roue1);
    SDL_RenderFillRect(renderer, &roue2);
    SDL_RenderPresent(renderer);
}

int main()
{
    SDL_DisplayMode screen;
    SDL_GetCurrentDisplayMode(0,&screen);
    const int width = screen.w;
    const int height = screen.h;
    SDL_Window *window = new_window(1000, 600, 100, 100);
    SDL_Renderer * renderer = new_renderer(window);
    //Dessin dans le renderer
    voiture(renderer,window);
    SDL_Delay(11000);
    clear_renderer(renderer);
    destroy_windows(window);
    

}