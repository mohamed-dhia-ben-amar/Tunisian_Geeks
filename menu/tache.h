/**
* @file tache.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "string.h"

//Détection de collision entre 2 entités en mouvement
/**
* @struct AABB
* @brief struct for entity
*/
typedef struct AABB {

  int x ;
  int y ;
  int w ;
  int h ;

}AABB;

//Afficher les entités secondaires
/**
* @struct ennemi
* @brief struct for ennemy
*/
typedef struct ennemi
{
  char nom_img_ennemi[20];
  SDL_Surface * img;
  SDL_Rect pos_img;

}ennemi;

void Afficher_ennemi(ennemi e );

void init_ennemi(int n) ;

int detecter_collision();
