#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "string.h"
#include "tache.h"

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
