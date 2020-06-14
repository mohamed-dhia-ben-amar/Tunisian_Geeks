#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.c"

int main() {
	SDL_Surface *screen;
        int running =1;/* pour la boucle de jeu*/
	int mv=4;/*pas de scrolling*/
        screen = SDL_SetVideoMode(600,240,32,SDL_HWSURFACE);
	SDL_Event event;

	scrollImage img;
	SCROLL_Init(&img,"map.png");
       
	SDL_EnableKeyRepeat(1,1);/*pour saisir multiple touche*/
	
	while(running)
{
		while(SDL_PollEvent(&event))
{
		  if(event.type == SDL_QUIT ) running = 0;
			if(event.type == SDL_KEYDOWN)
				{ if(event.key.keysym.sym == SDLK_ESCAPE) 
                                     running = 0;

				if(event.key.keysym.sym == SDLK_RIGHT)
                                {
							

					if(img.clip.x < img.img->w -img.clip.w)/*scrolling a droit */
						img.clip.x += mv;
				}

				if(event.key.keysym.sym == SDLK_LEFT)/*scrolling a gauche */{
					if(img.clip.x > 0)
						img.clip.x -= mv;
				}

			}
		}


		SCROLL_Render(&img,&screen);/*bliter l'image du background dans sa nouvelle position */
             
                

               SDL_Delay(16);
		SDL_Flip(screen);
	}

	SDL_Quit();
	return 0;
}
