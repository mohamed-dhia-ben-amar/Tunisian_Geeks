#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "game.h"

void animateEnnemi(ent *E, SDL_Rect rects[], SDL_Surface *screen, SDL_Surface *Background, SDL_Rect positionFond, int i)
{

    if (i == 0)
    {
        if (E->State != ATTACKING)

        {
            E->spriteright = IMG_Load("fox-1.png");
            E->maxframe = 5;
        }
        if (E->State == ATTACKING)
        {
            E->spriteright = IMG_Load("mv1.png");
        }
    }
    if (i == 10)
    {

        if ((E->Direction == 1) && (E->State != DEAD))
        {
            E->spriteright = IMG_Load("mvt-1-1.png");
        }

        if ((E->Direction == 2) && (E->State != DEAD))
        {
            E->spriteright = IMG_Load("mvt-2.png");
        }
        if (E->State == DEAD)
        {
            E->spriteright = IMG_Load("mvt 1-3.png");
        }
    }

    SDL_BlitSurface(E->spriteright, &rects[E->curframe], screen, &E->dst);
    SDL_Flip(screen);
    SDL_Delay(100);

    E->curframe++;

    if (E->curframe == E->maxframe)
    {
        E->curframe = 0;
    }
}
