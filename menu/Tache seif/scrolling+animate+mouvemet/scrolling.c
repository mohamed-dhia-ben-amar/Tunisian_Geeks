/**
* @file scrolling.c
* @brief Testing Program.
* @author seif el islem ben sib
* @version 0.1
* @date june 01, 2015
*
* Testing program for animating
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"scrolling.h"
#include <math.h>

/**
* @brief To initialise the backgroud .
* @param scrollImage variable de structure
* @param path the noun of the image
* @return Nothing
*/
void SCROLL_Init(scrollImage *s,char* path){
	s->img = IMG_Load("map.png");
	s->position.x = s->position.y = s->position.w = s->position.h= 0;
	s->clip.x = s->clip.y = 0;
	s->clip.w = 5000;
	s->clip.h = 600;
}

/**
* @brief To render the background .
* @param scrollImage variable de structure
* @param screen where the render going to take place
* @return Nothing
*/
void SCROLL_Render(scrollImage *s, SDL_Surface **screen)
{
	SDL_BlitSurface(s->img,&s->clip,*screen,&s->position);
}
/**
* @brief To animated to right .
* @param aimepos postion of each frame
* @param frame the frame of hero
* @return Nothing
*/
void animed (SDL_Rect animepos[],int *frame)
{ 
if(*frame<4)
*frame=3;
(*frame)++;


if(*frame>7)
*frame=4;
}
/**
* @brief To animated to left .
* @param aimepos postion of each frame
* @param frame the frame of hero
* @return Nothing
*/
void animeg (SDL_Rect animepos[],int *frame)
{
if (*frame>=4)
*frame=-1;
(*frame)++;
if (*frame==2)
*frame=3;

if(*frame>3)
*frame=0;
}
/**
* @brief To animated to left .
* @param hero the hero struct
* @return Nothing
*/
void initializeHero(Hero* hero)
{
	SDL_Surface* tmp  ; 
         tmp = IMG_Load("anim.png");
	hero->image = tmp;
	SDL_Rect pos;
	pos.x=200; 
	pos.y=300-(20)/*hero.h*/; 

	hero->positionabs=pos;	
	
	SDL_Rect pos1;
	pos1.x=0;
	pos1.y=-50;
	
	hero->positionrel=pos1;
	
}



