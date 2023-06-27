#include <stdio.h>
#include <stdlib.h>
#include "sprites.h"
#include "../windows.h"
#include "images.h"

int main()
{
    SDL_Window *window = new_window(1000,432 , 500, 500);
    SDL_Renderer *renderer = new_renderer(window);
    SDL_Texture * background = load_texture_from_image("ressources/bg-1-1.png",renderer);
    SDL_Texture * mario = load_texture_from_image("ressources/mario.png",renderer);
    for (int frame = 0; frame<400; frame++) 
    {
        test_closewindows(window);
        SDL_RenderClear(renderer);
        displayImage(background,window,renderer,0,0,1000,200);
        displaySprite(mario,window,renderer,frame);
        
    }

    return 0;
}