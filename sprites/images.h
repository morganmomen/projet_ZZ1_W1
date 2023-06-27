#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture * load_texture_from_image(char * path, SDL_Renderer * renderer);
void displayImage(SDL_Texture* texture,SDL_Window* window,SDL_Renderer* renderer,int x, int y,int width, int height,int speed, int frame);