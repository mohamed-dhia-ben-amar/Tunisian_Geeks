
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
double v_x = cos(angle_init)*v_init;
double v_y = sin(angle_init)*v_init;
const double g = 9.81;
const double pi = 3.14;


typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *image;

SDL_Rect positionabs;
SDL_Rect positionrel;

};



typedef struct scrollImage
 {
	SDL_Surface *img;/* surface ou on va mettre le background*/
	SDL_Rect position,clip;
/*!< rectonge des postion  *//* rectongle */
} scrollImage;

void SCROLL_Init(scrollImage *s, char* path);
void SCROLL_Render(scrollImage *s, SDL_Surface **screen);
void initializeHero(Hero* hero);
void animeg (SDL_Rect animepos[],int *frame);
void animed (SDL_Rect animepos[],int *frame);
/*void delay(int number_of_seconds);*/


