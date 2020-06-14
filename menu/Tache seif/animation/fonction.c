/**
* @file fonction.c
* @brief Testing Program.
* @author seif el islem ben sib
* @version 0.1
* @date june 01, 2015
*
* Testing program for animating
*
*/
#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "fonction.h"


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
* @brief To initialise hero .
* @param hero our hero
* @return Nothing
*/
void initializeHero(Hero* hero)
{
	SDL_Surface* tmp  ; 
         tmp = IMG_Load("anim.png");
	hero->image = tmp;


	SDL_Rect pos;
	pos.x=0; 
	pos.y=220; 
	hero->positionimage=pos;
	
}

