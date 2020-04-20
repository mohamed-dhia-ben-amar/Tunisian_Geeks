#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


//seif
typedef struct scrollImage
 {
	SDL_Surface *img;/* surface ou on va mettre le background*/
	SDL_Rect position,clip;
/*!< rectonge des postion  *//* rectongle */
} scrollImage;

void SCROLL_Init(scrollImage *s, char* path);
void SCROLL_Render(scrollImage *s, SDL_Surface **screen);
//seif

//yasmine
typedef struct 
{
 int val_score; 
 SDL_Rect position_score;
 SDL_Surface *textescore;
 TTF_Font *police;
 SDL_Color couleur;
}score;

typedef struct
{
 int vie;
 SDL_Surface *imageV1;
 SDL_Surface *imageV2;
 SDL_Surface *imageV3;
 SDL_Rect position_vie1;
 SDL_Rect position_vie2;
 SDL_Rect position_vie3;
}vie;

typedef struct 
{
 SDL_Rect positionP; 
 SDL_Surface *imageP; 
 int direction;
 score score_p;
 vie vie_p;
}personnage;


personnage initialiser_PP();         
void afficher_PP(personnage *p); 

//yasmine

//dhia
typedef struct AABB {

  int x ;
  int y ;
  int w ;
  int h ;

}AABB;

//Afficher les entités secondaires
typedef struct ennemi
{
  char nom_img_ennemi[20];
  SDL_Surface * img;
  SDL_Rect pos_img;

}ennemi;

void Afficher_ennemi(ennemi e );

void init_ennemi(int n) ;

int detecter_collision();
//dhia