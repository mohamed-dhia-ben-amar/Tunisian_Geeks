#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "game.h"
#include <math.h>

void move_ennemi(ent *E, SDL_Rect posHero, int disteh, int i)
{
	if (i == 0)
	{
		if ((posHero.x < E->dst.x) && (disteh >= 300))
		{

			E->dst.x -= 4;
		}
		if ((disteh < 300))
			E->dst.x -= 18;
	}
	else if (i == 10)
	{
		if (posHero.x > E->dst.x)
		{
			E->dst.x += 6;
			E->Direction = 1;
		}
		else
		{
			E->dst.x -= 6;
			E->Direction = 2;
		}
	}
}
