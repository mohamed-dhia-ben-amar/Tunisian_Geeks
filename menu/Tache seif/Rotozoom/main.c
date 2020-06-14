/**
* @file main.c
* @brief Testing Program
* @author seif el islem ben sib
* @version 0.12
* @date Apr 20, 2019
*
* Testing program for Rotozoom
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include "rotozoom.h"
#include "rotozoom.c"


int main(int argc, char *argv[])
{

 rotozoom();

 SDL_Quit();

return 0;
}

