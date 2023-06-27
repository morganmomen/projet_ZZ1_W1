#include <stdio.h>
#include <stdlib.h>
#include "sprites.h"
#include "../windows.h"
#include "images.h"

int main()
{
    int background_width;
    int background_height;
    int x_bg1;
    int x_bg2;
    SDL_Window *window = new_window(1000,500 , 500, 200);
    SDL_Renderer *renderer = new_renderer(window);
    SDL_Texture * background1 = load_texture_from_image("ressources/bg-1-1.png",renderer);
    SDL_Texture * background2 = load_texture_from_image("ressources/bg-1-1.png",renderer);
    SDL_Texture * mario = load_texture_from_image("ressources/mario.png",renderer);
    SDL_QueryTexture(background1, NULL, NULL,&background_width, &background_height);
    for (int frame = 0; frame<400; frame++) 
    {
        x_bg1 = -frame*(background_width/400);
        x_bg2 = background_width-frame*(background_width/400);
        test_closewindows(window);
        if (x_bg1<-background_width) x_bg1 = background_width;
        if (x_bg2<-background_width)x_bg2 = background_width;
        displayImage(background1,window,renderer,x_bg1,500-background_height,background_width,background_height);
        displayImage(background2,window,renderer,x_bg2,500-background_height,background_width,background_height);
        displaySprite(mario,window,renderer,frame);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
        SDL_RenderClear(renderer);
    }

    return 0;
}