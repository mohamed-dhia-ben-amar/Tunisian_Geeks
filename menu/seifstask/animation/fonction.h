#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *image;

SDL_Rect positionimage;



};

void initializeHero(Hero* hero);
void animeg (SDL_Rect animepos[],int *frame);
void animed (SDL_Rect animepos[],int *frame);

