#include "draw.h"

void draw_rectangle(SDL_Renderer * renderer, int x, int y, int width, int height)
{
    SDL_Rect rect = {x,y,width,height};
    change_color(renderer);
    SDL_RenderFillRect(renderer, &rect);
       
}
void change_color(SDL_Renderer * renderer)
{
    srand(time(NULL));
    SDL_SetRenderDrawColor(renderer, rand()%255, rand()%255, rand()%255, 255);
}