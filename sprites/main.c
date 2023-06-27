#include <stdio.h>
#include <stdlib.h>
#include "sprites.h"
#include "../windows.h"
#include "images.h"

int main()
{
    int background_width;
    int background_height;
    int floor_width;
    int floor_height;
    int character_width;
    int character_height;
    int x_bg1;
    int x_bg2;
    SDL_Window *window = new_window(1000,500 , 500, 200);
    SDL_Renderer *renderer = new_renderer(window);
    SDL_Texture * background = load_texture_from_image("ressources/plx-1.png",renderer);
    SDL_Texture * plx1 = load_texture_from_image("ressources/plx-2.png",renderer);
    SDL_Texture * plx2 = load_texture_from_image("ressources/plx-3.png",renderer);
    SDL_Texture * plx3 = load_texture_from_image("ressources/plx-4.png",renderer);
    SDL_Texture * plx4 = load_texture_from_image("ressources/plx-5.png",renderer);
    SDL_Texture * floor = load_texture_from_image("ressources/jungle tileset.png",renderer);
    SDL_Texture * character = load_texture_from_image("ressources/run.png",renderer);

    SDL_QueryTexture(background, NULL, NULL,&background_width, &background_height);
    SDL_QueryTexture(floor, NULL, NULL,&floor_width, &floor_height);
    SDL_QueryTexture(character, NULL, NULL,&character_width, &character_height);
    for (int frame = 0; frame<400; frame++) 
    {
        test_closewindows(window);
        displayImage(background,window,renderer,0,0,background_width,background_height,0,frame);
        displayImage(plx1,window,renderer,0,0,background_width,background_height,1,frame);
        displayImage(plx2,window,renderer,0,0,background_width,background_height,2,frame);
        displayImage(plx3,window,renderer,0,0,background_width,background_height,3,frame);
        displayImage(plx4,window,renderer,0,0,background_width,background_height,4,frame);
        displayImage(floor,window,renderer,0,background_height-floor_height,background_width,background_height,5,frame);
        displayImage(plx1,window,renderer,background_width,0,background_width,background_height,1,frame);
        displayImage(plx2,window,renderer,background_width,0,background_width,background_height,2,frame);
        displayImage(plx3,window,renderer,background_width,0,background_width,background_height,3,frame);
        displayImage(plx4,window,renderer,background_width,0,background_width,background_height,4,frame);
        displayImage(floor,window,renderer,floor_width,background_height-floor_height,background_width,background_height,5,frame);
        displaySprite(character,window,renderer,frame);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
        SDL_RenderClear(renderer);
    }

    return 0;
}