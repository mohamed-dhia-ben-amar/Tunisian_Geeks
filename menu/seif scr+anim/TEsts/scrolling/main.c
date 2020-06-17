#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"scrolling.c"





int main() {
	
	SDL_Surface *screen;
        int running =1;/* pour la boucle de jeu*/
	int mv=6;/*pas de scrolling*/
        screen = SDL_SetVideoMode(1600,600,32,SDL_HWSURFACE);
	SDL_Event event;
	SDL_Surface *fond=NULL;
	
	int b=0,i;

	

SDL_Rect positionfond;
SDL_Rect animepos[8];
SDL_Rect positionrel;
SDL_Rect positionabs;

int frame=4;
Hero hero;
initializeHero(&hero);
animepos[0].x=0;
animepos[0].y=0;
animepos[0].w=128;
animepos[0].h=180;

animepos[1].x=128;
animepos[1].y=0;
animepos[1].w=109;
animepos[1].h=180;

animepos[2].x=237;
animepos[2].y=0;
animepos[2].w=167;
animepos[2].h=180;

animepos[3].x=404;
animepos[3].y=0;
animepos[3].w=130;
animepos[3].h=180;

animepos[4].x=554;
animepos[4].y=0;
animepos[4].w=147;
animepos[4].h=180;

animepos[5].x=681;
animepos[5].y=0;
animepos[5].w=129;
animepos[5].h=180;

animepos[6].x=700;
animepos[6].y=0; 
animepos[6].w=130;
animepos[6].h=180;

animepos[7].x=967;
animepos[7].y=0;
animepos[7].w=159;
animepos[7].h=180;




positionfond.x=0;
positionfond.y=0;



	scrollImage img;
	SCROLL_Init(&img,"map.png");
       
	SDL_EnableKeyRepeat(1,1);/*pour saisir multiple touche*/
	
	while(running)
{

	while(SDL_PollEvent(&event))
{
		  if(event.type == SDL_QUIT ) 
			running = 0;
			if(event.type == SDL_KEYDOWN)
				{ if(event.key.keysym.sym == SDLK_ESCAPE) 
                                     running = 0;

				if(event.key.keysym.sym == SDLK_RIGHT)
                                {
					//if(img.clip.x < img.img->w -img.clip.w)
						if(hero.positionabs.x<700)
					
						hero.positionabs.x+=12;
						img.clip.x += mv;

						animed(animepos,&frame);
						
				}

				if(event.key.keysym.sym == SDLK_LEFT){
					if(img.clip.x > 0)
						{
						img.clip.x -= mv;
						
						}
						animeg(animepos,&frame);
						hero.positionabs.x-=12;



				}
				if(event.key.keysym.sym == SDLK_UP)
					{
				
					 // EVOLUTION
            				//On avance de 1
          				 positionrel.x ++;

           				if(positionrel.x>=50)
            					{
              					 positionrel.x=-50;
            					}

            					//On met à "0" les pos abs:
           					 positionabs.x = 200;
           					 positionabs.y = 300-/*hero.h*/30;

            					//On calcule la valeur relative de y:
            					positionrel.y=(-0.04*(positionrel.x*positionrel.x)+100);

            					//On calcule maintenant les valeurs abs
           					 positionabs.x = positionabs.x + positionrel.x+50;
           					 positionabs.y = positionabs.y - positionrel.y;
				     	        }
								
			}
			
		}
		

		SCROLL_Render(&img,&screen);/*bliter l'image du background dans sa nouvelle position */
                SDL_BlitSurface(fond,NULL,screen, &positionfond);
		SDL_BlitSurface(hero.image,&animepos[frame],screen,&hero.positionabs);
		

             
               SDL_Delay(16);
		SDL_Flip(screen);
	}

	 SDL_FreeSurface(fond);
    	

	SDL_Quit();
	return 0;
	
}
