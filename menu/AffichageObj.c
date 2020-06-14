#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "game.h"

void affichageObj(object obj, SDL_Surface *screen)
{

    SDL_BlitSurface(obj.image, NULL, screen, &(obj.position));
    SDL_Flip(screen);
}
