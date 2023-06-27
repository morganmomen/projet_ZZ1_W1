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

void displayImage(SDL_Texture* texture,SDL_Window* window,SDL_Renderer* renderer,int x, int y,int width, int height)
{
    SDL_Rect 
        source = {0},                         // Rectangle définissant la zone de la texture à récupérer
        window_dimensions = {0},              // Rectangle définissant la fenêtre, on n'utilisera que largeur et hauteur
        destination = {0};

    SDL_QueryTexture(texture, NULL, NULL,&source.w, &source.h);

    destination.x = x;
    destination.y = y;
    destination.w = width;
    destination.h =source.h;              // On fixe les dimensions de l'affichage à  celles de la fenêtre

    SDL_RenderCopy(renderer, texture,&source,&destination);                 
    SDL_RenderPresent(renderer);                  
    SDL_Delay(500);
    
}