#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "game.h"

void initialiserObj(object *obj, char name[], int x, int y)
{

    obj->image = IMG_Load(name);
    if (obj->image == NULL)
    {
        printf("Can not load image of tux: %s \n ", SDL_GetError());
        exit(1);
    }
    else
    {

        obj->position.x = x;
        obj->position.y = y;
        obj->position.h = obj->image->h;
        obj->position.w = obj->image->w;
    }
}
