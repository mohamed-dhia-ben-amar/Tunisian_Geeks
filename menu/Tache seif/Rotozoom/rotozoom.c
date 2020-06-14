/**
* @file rotozoom.c
* @brief Testing Program
* @author seif el islem ben sib
* @version 0.13
* @date Apr 20, 2019
*
* Testing program for rotation + zoom
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include "rotozoom.h"
 
#define TEMPS       30 // Le temps qu'il y a entre chaque augmentation de l'angle.
/**
* @brief To rotation + zoom + affichage.
* @return Nothing
*/ 
void rotozoom()
{
    SDL_Surface *ecran = NULL, *image = NULL, *rotation = NULL;
    SDL_Rect rect;
    SDL_Event event;
    double angle = 0;//l'ongle effectuer apres la rotation
    double zoom = 0;//intensite de zoom
    int sens = 1;//sense de rotation
 
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Rotate+Zoom", NULL);
 
    image = SDL_LoadBMP("image.bmp");
 
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 
        tempsActuel = SDL_GetTicks();//temp depuis le programme a ete declanche
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2; //On augmente l'angle pour que l'image tourne sur elle-même.
 
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }
 
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 
        rotation = rotozoomSurface(image, angle, zoom, 0); //On transforme la surface image.
        
        //On repositionne l'image en fonction de sa taille.
        rect.x =  event.button.x - rotation->w / 2;
        rect.y =  event.button.y - rotation->h / 2;
 
        SDL_BlitSurface(rotation , NULL, ecran, &rect); //On affiche la rotation de la surface image.
        SDL_FreeSurface(rotation); //On efface la surface rotation car on va la redéfinir dans la prochaine boucle.
 
        if(zoom >= 2){sens = 0;}
        else if(zoom <= 0.5){sens = 1;}
 
        if(sens == 0){zoom -= 0.02;}
        else{zoom += 0.02;}
 
        SDL_Flip(ecran);
    }
 
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(image);
    SDL_Quit();
 
   
}
