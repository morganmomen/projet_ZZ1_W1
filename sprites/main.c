#include <stdio.h>
#include <stdlib.h>
#include "sprites.h"
#include "../windows.h"
#include "images.h"

int main()
{
    int background_width;
    int background_height;
    SDL_Window *window = new_window(1000,500 , 500, 200);
    SDL_Renderer *renderer = new_renderer(window);
    SDL_Texture * background = load_texture_from_image("ressources/bg-1-1.png",renderer);
    SDL_Texture * mario = load_texture_from_image("ressources/mario.png",renderer);
    SDL_QueryTexture(background, NULL, NULL,&background_width, &background_height);
    for (int frame = 0; frame<400; frame++) 
    {
        test_closewindows(window);
        
        displayImage(background,window,renderer,0,500-background_height,background_width,background_height);
        displaySprite(mario,window,renderer,frame);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
        SDL_RenderClear(renderer);
    }

    return 0;
}