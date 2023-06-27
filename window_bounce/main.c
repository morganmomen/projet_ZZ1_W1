#include "event_windows.h"
#include <time.h>

SDL_bool program_running = SDL_TRUE;
SDL_Event event;

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
    *posy=rand()%height;
    *modx=rand()%25;
    *mody=rand()%25;

    while (program_running)
    {
        test_closewindows(window);
        window_bounce(window,modx,mody,width,height);
    }
    free(modx);
    free(mody);
    free(posx);
    free(posy);
    destroy_windows(window);
}

