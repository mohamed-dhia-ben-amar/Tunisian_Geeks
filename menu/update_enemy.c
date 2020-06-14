#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "game.h"

void update_ennemi(ent *E, SDL_Rect posHero, SDL_Rect rects[], SDL_Surface *screen, SDL_Surface *Background, SDL_Rect positionFond, int c, int i)
{
	int distEH = E->dst.x - (posHero.x + 84); //car width = 84;
	printf("distEH = %d\t E->State = %d\n", distEH, E->State);
	switch (E->State)
	{
	case WAITING:
	{
		animateEnnemi(E, rects, screen, Background, positionFond, i);
		break;
	}

	case FOLLOWING:
	{
		animateEnnemi(E, rects, screen, Background, positionFond, i);
		move_ennemi(E, posHero, distEH, i);
		break;
	}

	case ATTACKING:
	{

		animateEnnemi(E, rects, screen, Background, positionFond, i);
		move_ennemi(E, posHero, distEH, i);
		break;
	}

	case DEAD:
	{
		animateEnnemi(E, rects, screen, Background, positionFond, i);

		break;
	}
	}

	updateEnnemiState(E, distEH, c, i);
}
