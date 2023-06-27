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
    SDL_Rect 
        source = {0},                         // Rectangle définissant la zone de la texture à récupérer
        window_dimensions = {0},              // Rectangle définissant la fenêtre, on n'utilisera que largeur et hauteur
        destination = {0};
    SDL_GetWindowSize(window, &window_dimensions.w,&window_dimensions.h);
    renderer = new_renderer(window);
    SDL_Texture * texture = load_texture_from_image("ressources/windows95.jpg",window,renderer);           // La texture dans laquelle sera copiée l'image bitmap

    SDL_QueryTexture(texture, NULL, NULL,&source.w, &source.h);       // Récupération des dimensions de l'image

    destination = window_dimensions;              // On fixe les dimensions de l'affichage à  celles de la fenêtre

    /* On veut afficher la texture de façon à ce que l'image occupe la totalité de la fenêtre */

    SDL_RenderCopy(renderer, texture,&source,&destination);                 // Création de l'élément à afficher
    SDL_RenderPresent(renderer);                  // Affichage                              // Pause en ms
    SDL_Delay(5000);
    SDL_RenderClear(renderer);                    // Effacer la fenêtre
    return 0;
}