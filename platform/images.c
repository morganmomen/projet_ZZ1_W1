#include "images.h"
#include "../windows.h"

SDL_Texture * load_texture_from_image(char * path, SDL_Renderer * renderer)
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

void displayImage(SDL_Texture* texture,SDL_Renderer* renderer,int x, int y,int width, int height,int speed,int frame)
{
    SDL_Rect 
        source = {0},
        window_dimensions = {0},
        destination = {0};

    SDL_QueryTexture(texture, NULL, NULL,&source.w, &source.h);

    window_dimensions.w = width;
    window_dimensions.h = height;

    destination.x = x-frame*speed;
    if (destination.x<-source.w)destination.x=source.w;
    destination.y = y;
    destination.w = width;
    destination.h =source.h;

    SDL_RenderCopy(renderer, texture,&source,&destination);                                   
    
}