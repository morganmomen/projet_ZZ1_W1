#include "images.h"

SDL_Texture * load_texture_from_image(char * path, SDL_Window * window, SDL_Renderer * renderer)
{
    SDL_Surface * image = IMG_Load(path);
    SDL_Texture * texture = NULL;
    if (image == NULL)
    {
        printf("Error loading image: %s\n", IMG_GetError());
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    if (texture == NULL)
    {
        printf("Error creating texture: %s\n", SDL_GetError());
        return NULL;
    }
    return texture;
}