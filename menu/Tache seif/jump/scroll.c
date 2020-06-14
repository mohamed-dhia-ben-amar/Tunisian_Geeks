/**
* @file scroll.c
* @brief Testing Program
* @author seif el islem ben sib
* @version 0.1
* @date Apr 20, 2019
*
* Testing program for background scrollilng
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"


/**
* @brief To scroll to right .
* @param rect hero struct
* @param positionFond where we will blit
* @return Nothing
*/
void scrollingright(SDL_Rect *rect , SDL_Rect *positionFond )
     {

  

  if ((( rect->x>=640 )||(rect->x>=1280))&&(positionFond->x<3840))
{
 positionFond->x+=640;
rect->x=0 ; 

}

}
/**
* @brief To scroll to left .
* @param rect hero struct
* @param positionFond where we will blit
* @return Nothing
*/
void scrollingleft(SDL_Rect *rect , SDL_Rect *positionFond )
     {

  

if ( rect->x==0)
{
 positionFond->x-=640;
rect->x=640-rect->x ; 

}

}
