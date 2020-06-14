
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

void SCROLL_Init(scrollImage *s, char* path);
void SCROLL_Render(scrollImage *s, SDL_Surface **screen);



