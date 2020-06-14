#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

//definition de STATE
typedef enum STATE STATE;
enum STATE
{
    WAITING,
    FOLLOWING,
    ATTACKING,
    DEAD
};

//definition de la structure "object"
typedef struct
{

    SDL_Surface *image;
    SDL_Rect position;

} object;

//definition de la structure "Player"
typedef struct
{

    SDL_Surface *image, *image2;
    SDL_Rect position;
    SDL_Rect rect[20];

} Player;

//definition de la structure "ent"
typedef struct
{

	SDL_Rect position_entite; //pos de "ent"
	SDL_Rect position_map; //pos de "map"
	SDL_Rect frame; //pos de "frame"
	SDL_Rect dst; //pos de "dst" ou distance

	SDL_Surface *image_entite; //surface pour l'image de "ent" 
	SDL_Surface *spriteleft; //surface pour l'image de "ent" au cas du mvt vers la gauche
	SDL_Surface *spriteright; //surface pour l'image de "ent" au cas du mvt vers la droite

	int pos_alea_max_x; 
	int pos_alea_min_x;

	int pos_alea_max_y;
	int pos_alea_min_y;

	int pos_max_x;
	int pos_min_x;

	int pos_max_y;
	int pos_min_y;

	int curframe; //frame courant
	int maxframe; //frames totals

	int Direction; 
	STATE State;

} ent;

void initialiserObj(object *obj, char name[], int x, int y);
void affichageObj(object obj, SDL_Surface *sscreen);

void move_ennemi(ent *E, SDL_Rect posHero, int disteh, int i);
void update_ennemi(ent *E, SDL_Rect posHero, SDL_Rect rects[], SDL_Surface *screen, SDL_Surface *Background, SDL_Rect positionFond, int c, int i);
void updateEnnemiState(ent *E, int distEH, int c, int i);
void animateEnnemi(ent *E, SDL_Rect rects[], SDL_Surface *screen, SDL_Surface *Background, SDL_Rect positionFond, int i);

#endif // GAME_H_INCLUDED