
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"


void animate(SDL_Surface *screen ,  SDL_Surface *Background ,SDL_Surface *image2, SDL_Rect *positionFond  , int *running)
{

SDL_Rect rect ;

rect.x=0;
rect.y=100;
rect.h=50 ; 
rect.w=40 ; 

SDL_Rect posMarioRel;
    posMarioRel.x = 20;
    posMarioRel.y = 20;

    //Variables méthode 2:
    const double g = 9.81;
    const double pi = 3.14;
    int v_init = 2;
    int angle_init = pi/4;
    int t = 0;
    double v_x = cos(angle_init)*v_init;
    double v_y = sin(angle_init)*v_init;

int left,right,up,x,i=0,pr,y;
//extraire("css.txt",&(positionFond->x),&(rect.x)); 

 SDL_BlitSurface(Background ,positionFond,screen,NULL);
SDL_Flip(screen) ; 
SDL_EnableKeyRepeat(1,1) ; 
while(running)
{

                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = 0;
                          
                                        break;
				case SDL_KEYDOWN:
					if(event.key.keysym.sym==SDLK_RIGHT)
                                              { 

                                               right=1;
                                                left=0;
						rect.x += 5;
                                                                                                                             
                                  scrollingright(&rect , positionFond );
                                                 }
					if(event.key.keysym.sym==SDLK_LEFT)
						{ 
                                                right=0;
                                                left=1;
						rect.x -= 5;
                                       scrollingleft(&rect ,positionFond );
                                       
                                                 }
					

                           if(event.key.keysym.sym==SDLK_UP)
                                   {  

            rect.y = 900-(image2->h);
            posMarioRel.x=(int)(v_x*t);
            posMarioRel.y=(int)((v_y*t)-((g*pow(t,2)/2000)));

            //On calcule maintenant les valeurs absolues
if(right==1)
{
            rect.x = rect.x + 0.1*posMarioRel.x;
            rect.y = rect.y + posMarioRel.y;
 if( rect.y>1060)
{
  rect.y=513;

}

        //Intervalle de 10ms

        t+=10;


        // FIN EVOLUTION
        //Avec en bonus une petite mise a 0 des coordonnees lorsque mario s'en va trop loin :)
        if(rect.y<=100)
        {
            t=0;
        }
scrollingright(&rect , positionFond );
}
if(left==1)
{
            rect.x = rect.x - 0.1*posMarioRel.x;
            rect.y = rect.y + posMarioRel.y;
 if( rect.y>1060)
{
  rect.y=513;

}

        //Intervalle de 10ms

        t+=10;


        // FIN EVOLUTION
        //Avec en bonus une petite mise a 0 des coordonnees lorsque mario s'en va trop loin :)
        if(rect.y<=100)
        {
            t=0;
        }
scrollingleft(&rect , positionFond );
}
}
 
                                    
                                   

      if(event.key.keysym.sym==SDLK_SPACE)
    {i=0;
i++;
if(right==1)
{
if(i==1)
{
rect.x+=20;
scrollingright(&rect , positionFond );
}
else if(i==2)
{
rect.x+=30;
scrollingright(&rect , positionFond );
}
else if(i==3)
{
rect.x+=40;
scrollingright(&rect , positionFond );
}  
else if(i>4)
{
rect.x+=50;
scrollingright(&rect , positionFond );
}
}
else if(left==1)
{
if(i==1)
{
rect.x-=20;
scrollingleft(&rect , positionFond );
 
}
else if(i==2)
{
rect.x-=30;
scrollingleft(&rect , positionFond );
 
}
else if(i==3)
{
rect.x-=40;
scrollingleft(&rect , positionFond );
 
}  
else if(i>4)
{
rect.x-=50;
scrollingleft(&rect , positionFond );

}
}
}


				break;
				case SDL_KEYUP:
					if(event.key.keysym.sym==SDLK_UP)
{
                                        while(rect.y!=535) 
                                        {
					rect.y++;
}					}

				break;
						
					}
SDL_BlitSurface(Background,positionFond,screen,NULL);

SDL_BlitSurface(image2,NULL, screen, &rect);


SDL_Flip(screen) ;
}
}

}


