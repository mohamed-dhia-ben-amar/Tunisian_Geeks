#include <stdio.h>
#include <stdlib.h>
#include "personnage.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"


personnage initialiser_PP()
{  
    personnage p;   

   p.imageP =IMG_Load("Idle(1).png");
   p.positionP.x=0;
   p.positionP.y=250;

     if(p.imageP==NULL)
      { 
        printf("unable to set load png :%s\n",SDL_GetError());
        
      }

   p.direction=1; // 1=droite et  (-1) =gauche

  //partie score
   p.score_p.val_score =00;
   p.score_p.position_score.x =400; // a modifier
   p.score_p.position_score.y =0;

     if(TTF_Init() ==-1)
       {
         fprintf(stderr,"Erreur d'initialisation de TTF_Init :%s\n",TTF_GetError());
         exit(EXIT_FAILURE);      
       }

   p.score_p.police= TTF_OpenFont("Simplicity.ttf",40); 
  // p.score_p.couleur= {255, 255, 255};
   p.score_p.textescore= TTF_RenderText_Blended(p.score_p.police,"score=",p.score_p.couleur);

//partie vie 
  p.vie_p.vie =3;
  p.vie_p.imageV1= IMG_Load("airplaneb.png");
  p.vie_p.imageV2= IMG_Load("airplaneb.png");
  p.vie_p.imageV3= IMG_Load("airplaneb.png");
     if((p.vie_p.imageV1==NULL) || (p.vie_p.imageV2==NULL) || (p.vie_p.imageV3==NULL))
       {
         printf("unable to set load png :%s\n",SDL_GetError());
         
       }
  //les positions des images des vies 
  
  p.vie_p.position_vie1.x= 450;
  p.vie_p.position_vie1.y= 0;
  p.vie_p.position_vie2.x= 550;
  p.vie_p.position_vie2.y= 0;
  p.vie_p.position_vie3.x= 650;
  p.vie_p.position_vie3.y= 0;

return p;

}



void afficher_PP(personnage *p)
{ SDL_Surface *screen=NULL;

  if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
     printf("unable to initialize SDL: %s\n",SDL_GetError());
     
    }

screen=SDL_SetVideoMode(2000,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
   if(screen==NULL)
    {
     printf("unable to set video mode: %s\n",SDL_GetError());
     
    }

 SDL_BlitSurface(p->imageP,NULL,screen,&p->positionP);
 //SDL_BlitSurface(p->score_p.textescore,NULL,screen,&p->score_p.position_score);
 SDL_BlitSurface(p->vie_p.imageV1,NULL,screen,&p->vie_p.position_vie1);
 SDL_BlitSurface(p->vie_p.imageV2,NULL,screen,&p->vie_p.position_vie2);
 SDL_BlitSurface(p->vie_p.imageV3,NULL,screen,&p->vie_p.position_vie3);

SDL_Delay(1000);
SDL_Flip(screen);

}


/*personnage animer_PP(personnage p)
{


}

      						








/*personnage deplacer_PP_souris(personnage p)
{ SDL_Event event; 
  while(SDL_PollEvent(&event))
   {

     if (event.type==mouse)
	{switch()
	  


	}
   }	 	 




}*/
