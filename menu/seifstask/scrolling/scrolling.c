
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include"scrolling.h"

//initialiser l'image du background et sa position initial
void SCROLL_Init(scrollImage *s/*variable de structure*/,char* path/*nom du image */){

	s->img = IMG_Load("map.png");
	s->position.x = s->position.y = s->position.w = s->position.h= 0;
	s->clip.x = s->clip.y = 0;
	s->clip.w = 600;
	s->clip.h = 240;
}

void perso_Init(perso *p1,char* path){

	p1->body = IMG_Load("p1.png");
	p1->position.x =5;
	 p1->position.y = 160;
	p1->position.w = 0;
	p1->position.h= 0;
	p1->clip.x = p1->clip.y = 0;
	p1->clip.w = 10;
	p1->clip.h = 8;
	
}
//bliter l'image du background dans sa nouvelle position 

void SCROLL_Render(scrollImage *s, SDL_Surface **screen)
{
	SDL_BlitSurface(s->img,&s->clip,*screen,&s->position);
}

void perso_Render(perso *p1, SDL_Surface **screen)
{
	SDL_BlitSurface(p1->body,NULL,*screen,&p1->position);
}

