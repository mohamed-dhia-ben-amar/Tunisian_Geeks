
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"

//initialiser l'image du background et sa position initial
void SCROLL_Init(scrollImage *s/*variable de structure*/,char* path/*nom du image */){
	s->img = IMG_Load("/home/dhia/Desktop/Tunisian_Geeks-master/Tunisian_Geeks/seifstask/map.png");
	s->position.x = s->position.y = s->position.w = s->position.h= 0;
	s->clip.x = s->clip.y = 0;
	s->clip.w = 600;
	s->clip.h = 240;
}
//bliter l'image du background dans sa nouvelle position 

void SCROLL_Render(scrollImage *s/* variable de structure */, SDL_Surface **screen/*surface */)
{
	SDL_BlitSurface(s->img,&s->clip,*screen,&s->position);
}


