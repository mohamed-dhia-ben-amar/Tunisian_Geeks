#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "/home/dhia/Desktop/Tunisian_Geeks-master/Tunisian_Geeks/seifstask/scrolling.c"
#include "/home/dhia/Desktop/Tunisian_Geeks-master/Tunisian_Geeks/Yasmine/personnage.c"

//seif

//initialiser l'image du background et sa position initial
void SCROLL_Init(scrollImage *s/*variable de structure*/,char* path/*nom du image */){
	s->img = IMG_Load("map.png");
	s->position.x = s->position.y = s->position.w = s->position.h= 0;
	s->clip.x = s->clip.y = 0;
	s->clip.w = 600;
	s->clip.h = 240;
}
//bliter l'image du background dans sa nouvelle position 

void SCROLL_Render(scrollImage *s/* variable de structure */, SDL_Surface **screen/*surface */)
{
	SDL_BlitSurface(s->img,&s->clip,*screen,&s->position);
}

//seif

//yasmine
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
//yasmine

//dhia
int detecter_collision()
{
  AABB perso;
  AABB ennemi;
  if ((perso.x + perso.w < ennemi.x) || (perso.x > ennemi.x + ennemi.w) || (perso.y + perso.h  < ennemi.h) || (perso.y > ennemi.y + ennemi .h))
    return 0;
  else
    return 1;
}

void Afficher_ennemi(ennemi e )
{
  SDL_Surface* screen;
  SDL_BlitSurface(e.img, NULL, screen, &e.pos_img);
}

void init_ennemi(int n)
{ //Fonction travaille par seif
  ennemi e[10];
  int i;
  for (i = 0; i < n; i++) 
  {
    strcat(e[i].nom_img_ennemi, ".bmp");
    e[i].img = SDL_LoadBMP(e[i].nom_img_ennemi);
    e[i].pos_img.x = rand()%30+1;
    srand(30);
    e[i].pos_img.y = 500;//à regler apres la finalisation du jeu
    e[i].pos_img.w = e[i].img->w;
    e[i].pos_img.h = e[i].img->h;
    Afficher_ennemi(e[i]);
  }
}
//dhia