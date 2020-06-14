#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "game.h"

void updateEnnemiState(ent *E, int distEH, int c, int i)
{

   switch (E->State)
   {

   case WAITING:
   {
      if (i == 0)
      {
         if ((distEH > 100) && (distEH < 600))
            E->State = FOLLOWING;
      }
      if (i == 10)
      {
         if ((distEH > 100) && (distEH < 400))
            E->State = FOLLOWING;
      }

      break;
   }

   case FOLLOWING:
   {
      if (i == 0)
      {

         if ((distEH > 0) && (distEH < 100))
            E->State = ATTACKING;
      }
      if (i == 10)
      {
         if ((distEH > 0) && (distEH < 200))
            E->State = ATTACKING;
      }

      break;
   }

   case ATTACKING:
   {
      if (i == 0)
      {
         if (distEH <= 0)
            E->State = WAITING;
      }
      if (i == 10)
      {
         if (c != 0)
            E->State = DEAD;
      }

      break;
   }
   }
}
