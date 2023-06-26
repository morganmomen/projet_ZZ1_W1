#include "event_windows.h"
#include <time.h>


int main()
{
    SDL_DisplayMode screen;
    SDL_GetCurrentDisplayMode(0,&screen);
    const int width = screen.w;
    const int height = screen.h;
    srand(time(2));
    int *modx = malloc(sizeof(int));
    int *mody = malloc(sizeof(int));
    int *posx = malloc(sizeof(int));
    int *posy = malloc(sizeof(int));
    *posx=rand()%width;
    *posy=rand()%height;
    *modx=rand()%100;
    *mody=rand()%100;
    SDL_Window *window = NULLs;

    window = new_window(300,200,*posx,*posy);

    while (SDL_TRUE)
    {
        window_movement(window,modx,mody,posx,posy);
    }
    free(modx);
    free(mody);
    free(posx);
    free(posy);
    destroy_windows(window);

}

