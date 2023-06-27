#include "event_windows.h"
#include "../windows.h"
#include <time.h>

SDL_bool program_running = SDL_TRUE;
SDL_Event event;

int main()
{
    SDL_DisplayMode screen;
    int *modx = malloc(sizeof(int));
    int *mody = malloc(sizeof(int));
    SDL_Window *window =new_window(500,200,300,300);
    SDL_Renderer * renderer = new_renderer(window);
    SDL_GetCurrentDisplayMode(SDL_GetWindowDisplayIndex(window),&screen);

    srand(time(0));
    *modx=rand()%25;
    *mody=rand()%25;

    while (program_running)
    {
        test_closewindows(window,renderer);
        window_bounce(window,renderer,modx,mody,screen.w,screen.h);
    }
    free(modx);
    free(mody);
    endSDL(window,renderer);
    return 0;
}

