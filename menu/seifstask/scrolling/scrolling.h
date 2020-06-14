
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



typedef struct scrollImage
 {
	SDL_Surface *img;/* surface ou on va mettre le background*/
	SDL_Rect position,clip;
/*!< rectonge des postion  *//* rectongle */
} scrollImage;

typedef struct perso
 {
	SDL_Surface *body;
	SDL_Rect position,clip;
	char dir;
} perso;


void SCROLL_Init(scrollImage *s, char* path);
void SCROLL_Render(scrollImage *s, SDL_Surface **screen);

void perso_Init(perso *p1, char* path);
void perso_Render(perso *p1, SDL_Surface **screen);




