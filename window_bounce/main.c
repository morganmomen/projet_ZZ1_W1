#include "event_windows.h"
#include <time.h>



int main()
{
    
    SDL_DisplayMode screen;
    int *modx = malloc(sizeof(int));
    int *mody = malloc(sizeof(int));
    int *posx = malloc(sizeof(int));
    int *posy = malloc(sizeof(int));
    SDL_Window *window = NULL;
    window = new_window(300,200,*posx,*posy);
    SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(window),&screen);
    const int width = screen.w;
    const int height = screen.h;

    srand(time(0));
    *posx=rand()%width;
    srand(time(1));
    *posy=rand()%height;
    srand(time(2));
    *modx=rand()%25;
    srand(time(3));
    *mody=rand()%25;

    while (SDL_TRUE)
    {
        window_bounce(window,modx,mody,width,height);
    }
    free(modx);
    free(mody);
    free(posx);
    free(posy);
    destroy_windows(window);

}

