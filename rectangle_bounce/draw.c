#include "draw.h"

void draw_rectangle(SDL_Renderer * renderer, int x, int y, int width, int height)
{
    SDL_Rect rect = {x,y,width,height};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
    SDL_RenderFillRect(renderer, &rect);
       
}