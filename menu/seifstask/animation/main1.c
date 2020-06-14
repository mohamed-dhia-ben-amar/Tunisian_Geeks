#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "fonction.c"


int main (void)
{
SDL_Surface *screen =NULL;
SDL_Init(SDL_INIT_VIDEO);
//SDL_EnableKeyRepeat(10,40);
int continuer=1;
screen = SDL_SetVideoMode(1500,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_Surface *fond=NULL;

SDL_Rect positionfond;
SDL_Rect animepos[8];
SDL_Event event;
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

fond= IMG_Load("background.png");

while (continuer == 1)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {   
		            case SDLK_ESCAPE:
			        continuer=0;
			        break; 
		    
                    case SDLK_UP: 
                    hero.positionimage.y -= 4;
                    break;
            
                    case SDLK_DOWN:
                    hero.positionimage.y +=2;
                    break;
                    
                    case SDLK_RIGHT:
                    animed(animepos,&frame);
                    hero.positionimage.x+=20;
                    break;

                    case SDLK_LEFT: 
                    animeg(animepos,&frame);
			        hero.positionimage.x-=20;
                    break;
                }
        }
        SDL_BlitSurface(fond,NULL,screen, &positionfond);
        SDL_BlitSurface(hero.image,&animepos[frame],screen,&hero.positionimage);
        SDL_Flip(screen);
    }

}
