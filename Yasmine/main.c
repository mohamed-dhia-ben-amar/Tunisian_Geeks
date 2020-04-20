#include <stdio.h>
#include <stdlib.h>
#include "personnage.c"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"



int main ()
{ int continuee=1;
 personnage p;
SDL_Event event;

while (continuee)
{
p=initialiser_PP();
afficher_PP(&p);


while(SDL_PollEvent(&event))
		{
		  if(event.type == SDL_QUIT ) continuee = 0;
			if(event.type == SDL_KEYDOWN)
				{ 
				    if(event.key.keysym.sym == SDLK_ESCAPE) 
                                     continuee = 0;


}}}

return 0;

}
