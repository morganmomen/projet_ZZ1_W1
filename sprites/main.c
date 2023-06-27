#include <stdio.h>
#include <stdlib.h>
#include "sprites.h"
#include "../windows.h"
#include "images.h"

int main()
{
    SDL_Renderer *renderer;
    int width = 1000;
    int height = 500;
    SDL_Window *window = new_window(width,height , 500, 500);
    renderer = new_renderer(window);
    SDL_Texture * background = load_texture_from_image("ressources/windows95.jpg",window,renderer);
    SDL_Texture * mario = load_texture_from_image("ressources/mario.png",window,renderer);
    //displayImage(background,window,renderer,0,0,width,height);
    displaySprite(mario,window,renderer);
    return 0;
}