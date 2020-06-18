#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "scrolling.h"

//initialiser l'image du background et sa position initial
void SCROLL_Init(scrollImage *s /*variable de structure*/, char *path /*nom du image */)
{
	s->img = IMG_Load("map.png");
	s->position.x = s->position.y = s->position.w = s->position.h = 0;
	s->clip.x = s->clip.y = 0;
	s->clip.w = 5000;
	s->clip.h = 600;
}
//bliter l'image du background dans sa nouvelle position

void SCROLL_Render(scrollImage *s /* variable de structure */, SDL_Surface **screen /*surface */)
{
	SDL_BlitSurface(s->img, &s->clip, *screen, &s->position);
}

void animed(SDL_Rect animepos[], int *frame)
{
	if (*frame < 4)
		*frame = 3;
	(*frame)++;

	if (*frame > 7)
		*frame = 4;
}

void animeg(SDL_Rect animepos[], int *frame)
{
	if (*frame >= 4)
		*frame = -1;
	(*frame)++;
	if (*frame == 2)
		*frame = 3;

	if (*frame > 3)
		*frame = 0;
}

void initializeHero(Hero *hero)
{
	SDL_Surface *tmp;
	tmp = IMG_Load("anim.png");
	hero->image = tmp;
	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0 /*hero.h*/;

	hero->positionabs = pos;

	SDL_Rect pos1;
	pos1.x = 0;
	pos1.y = 0;

	hero->positionrel = pos1;
}
