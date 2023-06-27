#include "sprites.h"

void displaySprite(SDL_Texture * texture, SDL_Window * window, SDL_Renderer * renderer, int frame)
{
    SDL_Event event;
    SDL_Rect 
        source = {0},                         // Rectangle définissant la zone de la texture à récupérer
        window_dimensions = {0},              // Rectangle définissant la fenêtre, on n'utilisera que largeur et hauteur
        destination = {0},
        state={0};
    int x =0;
    SDL_GetWindowSize(window, &window_dimensions.w, &window_dimensions.h);
    SDL_QueryTexture(texture, NULL, NULL,&source.w, &source.h);

    int nb_images= 8;
    float zoom = 2.5; 
    int offset_x = source.w / nb_images;
    int offset_y = source.h;

    state.x = 0;
    state.y = offset_y*0;
    state.w = offset_x;
    state.h = offset_y;

    destination.w = offset_x * zoom;
    destination.h = offset_y * zoom;

    destination.x = window_dimensions.w/2;
    destination.y = window_dimensions.h-source.h*zoom-30;

    state.x += frame*offset_x;
    state.x%=source.w;
    SDL_RenderCopy(renderer, texture,&state,&destination);

}