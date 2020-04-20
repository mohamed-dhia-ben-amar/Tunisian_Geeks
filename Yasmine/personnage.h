#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

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
/*personnage deplacer_PP_souris(personnage p); */          
//personnage animer_PP(personnage p);             


#endif // PERSONNAGE_H_INCLUDED
