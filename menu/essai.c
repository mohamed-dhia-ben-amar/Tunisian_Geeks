#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "tache.h"

typedef struct _s
{

  SDL_Surface* image;
  SDL_Surface* hoverImage;
  SDL_Rect pos;


  int clickEvent;
  int exitEvent;
  int PlusEvent;
  int MinusEvent;
  int type;
  int visible;
  int order;
  int ShowMenu;
  int fs;
} Sprite;


Sprite* Sprites[100];
int nSprites = 0;
int gameRunning = 1;
int cMouseOver = -1;
int mouseDown = 0;
int processedClick = 0;

Sprite* MakeSprite(char name[], int type)
{
  char fname[40] = "";
  strcpy(fname, name);
  strcat(fname, ".bmp");
  Sprite* sprite = malloc(sizeof(Sprite));
  sprite->image = SDL_LoadBMP(fname);
  SDL_SetColorKey(sprite->image,SDL_SRCCOLORKEY,SDL_MapRGB(sprite->image->format,0,0,0));
  sprite->visible = 1;
  sprite->type=type;
  sprite->clickEvent = 0;
  if(type==1)
  {
    char hname[30] = "";
    strcat(hname, name);
    strcat(hname, " hover.bmp");
    sprite->hoverImage = SDL_LoadBMP(hname);
    SDL_SetColorKey(sprite->hoverImage,SDL_SRCCOLORKEY,SDL_MapRGB(sprite->hoverImage->format,0,0,0));
  }
  Sprites[nSprites++] = sprite;
  return sprite;
}

void checkMouse()
{
  cMouseOver = -1;
  int mx,my;
  SDL_GetMouseState(&mx, &my);
  for(int o=nSprites-1; o>=0; o--)
  {
    if(Sprites[o]->pos.x<=mx && Sprites[o]->pos.y<=my && Sprites[o]->pos.x+Sprites[o]->pos.w>=mx && Sprites[o]->pos.y+Sprites[o]->pos.h>=my)
    {
      cMouseOver = o;
      break;
    }
  }
}

Sprite* addButton(char name[], int x, int y)
{
  Sprite* btn = MakeSprite(name, 1);
  btn->pos.x = x;
  btn->pos.y = y;
  btn->pos.w = 100;
  btn->pos.h = 27;

  return btn;
}

Sprite* addButton2(char name[], int x, int y)
{
  Sprite* btn = MakeSprite(name, 0);
  btn->pos.x = x;
  btn->pos.y = y;
  btn->pos.w = 100;
  btn->pos.h = 27;

  return btn;
}

void processClickEvent(int e)
{
  if (e%2 == 0)
    /*Sprites[0]->image = SDL_LoadBMP("ICON.bmp")*/;
  if (e%2 != 0)
    /*Sprites[0]->image = SDL_LoadBMP("bg.bmp")*/;
}
void processexitEvent(int e)
{
  switch(e)
  {
    case 1:
      {
        exit(0);
        break;
      }
  }
}

void plusMusic(int *volume)
{
  (*volume) += 1;
}

void minusMusic(int *volume)
{
  (*volume) -= 1;
}

void texte(SDL_Surface *ecran)
{

//initialisation ttf
TTF_Init();

//declaration
SDL_Surface* text = NULL;
SDL_Rect posText;

//initialisation de la position du texte
posText.x = 250;
posText.y = 50;

//creer une police
TTF_Font *font;
font = TTF_OpenFont("font.ttf", 40);
SDL_Color fontcolor = {0, 0, 0};

//creer une zone texte
text = TTF_RenderText_Blended(font, "Lost in EGYPT", fontcolor);
SDL_BlitSurface(text, NULL, ecran, &posText);

//fermer
SDL_Flip(ecran);
TTF_CloseFont(font); /*closing the font before freeing the momory*/
}

int main()
{
  int test_menu=0;
  int test=1,gamma=-1;
  int volume;
  SDL_Delay(1000);
  SDL_Surface *screen;
  char pause;
  //texte(screen);
  //song
  	 if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
     {
        printf("%s", Mix_GetError());
     }
     Mix_Music *musique=NULL; //Création du pointeur de type Mix_Music
     Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
     musique = Mix_LoadMUS("Misplaced"); //Chargement de la musique
     Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
     //son bref
  Mix_AllocateChannels(32); //Allouer 32 canaux
  Mix_Volume(1, MIX_MAX_VOLUME/2); //Mettre à mi-volume le post 1
  Mix_Chunk *son;//Créer un pointeur pour stocker un .WAV
  son = Mix_LoadWAV("son.wav"); //Charger un wav dans un pointeur
  Mix_VolumeChunk(son, MIX_MAX_VOLUME*250000); //Mettre un volume pour ce wav

  if(SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("Unable to initialize SDL: %s\n", SDL_GetError());
    return 1;
  }
  screen = SDL_SetVideoMode(1582, 704, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if(screen==NULL)
  {
    printf("Unable to set video mode : %s\n", SDL_GetError());
    return 1;
  }
  Sprite* bg = MakeSprite("bg", 0);
  bg->pos.x = 0;
  bg->pos.y = 0;
  bg->pos.w = 800;
  bg->pos.h = 480;
  Sprite* contBtn = addButton("play1", 1000, 120);
  contBtn->clickEvent = 1;
  Sprite* contBtn5 = addButton("settings", 1100, 240);
  contBtn5->ShowMenu = 1;
  addButton("scoreboard1", 1000, 360);
  addButton("credits1", 1100, 480);
  Sprite* contBtn2 = addButton("quit11", 1000, 600);
  contBtn2->exitEvent = 1;
  SDL_Delay(1000);
  while(gameRunning==1)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        gameRunning = 0;
      }

      else if(event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN)
      {
        mouseDown = 1;
      }
      else if(event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONUP)
      {
        mouseDown = 0;
        processedClick = 0;
      }
      else if (event.key.keysym.sym == SDLK_UP)
      {
        gamma++;
        SDL_BlitSurface(Sprites[gamma]->hoverImage, NULL, screen, &Sprites[gamma]->pos);
        SDL_Delay(1000);
        printf("%d\n",gamma );
      }
      else if (event.key.keysym.sym == SDLK_DOWN)
      {
        if (gamma >= 1)
        {
          {
            gamma--;
            SDL_BlitSurface(Sprites[gamma]->hoverImage, NULL, screen, &Sprites[gamma]->pos);
          }
        }
      }
      else
      {

      }
    }
    checkMouse();
    for(int o=0; o<nSprites; o++)
    {
      if(Sprites[o]->visible != 1) continue;
      if(Sprites[o]->type==1 || Sprites[o]->type==0)
      {
        if(cMouseOver==o)
        {
          if(mouseDown==1)
          {
            if(processedClick == 0)
            {
              Mix_PlayChannel(1,son,0);
            }
            if(processedClick==0 && Sprites[o]->clickEvent != -1)
            {
              test++;
              processClickEvent(test);
            }
            if(processedClick==0 && Sprites[o]->exitEvent != -1)
            {
              processexitEvent(Sprites[o]->exitEvent);
            }
            if(processedClick==0 && Sprites[o]->MinusEvent != -1)
            {
              // down volume code here
            }
            if(processedClick==0 && Sprites[o]->PlusEvent != -1)
            {
              // up volume code here
            }
            if(processedClick==0 && Sprites[o]->ShowMenu == 1)
            {
              SDL_Surface* screen2 = screen;
              Sprite* sett_menu = addButton2("settings_menu",200,200);
              sett_menu->hoverImage = sett_menu->image;
              SDL_BlitSurface(sett_menu->image, NULL, screen2, &sett_menu->pos);
              Sprite* contBtn3 = addButton("minus", 440, 320);
              contBtn3->MinusEvent = 1;
              Sprite* contBtn4 = addButton("plus", 550, 320);
              contBtn4->PlusEvent = 1;
              Sprite* contBtn5 = addButton("off_fs", 440, 480);
              contBtn5->fs=0;
              Sprite* contBtn6 = addButton("on_fs", 550, 480);
              contBtn6->fs=1;
            }
            if(processedClick==0 && Sprites[o]->fs == 1)
            {
              screen=SDL_SetVideoMode(bg->pos.x,bg->pos.x,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
            }
            if(processedClick==0 && Sprites[o]->fs == 0)
            {
              screen = SDL_SetVideoMode(1582, 704, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
            }
          }
          else
            SDL_BlitSurface(Sprites[o]->hoverImage, NULL, screen, &Sprites[o]->pos);
        }
        else
        {
          SDL_BlitSurface(Sprites[o]->image, NULL, screen, &Sprites[o]->pos);
        }
      }
      else
      {
        SDL_BlitSurface(Sprites[o]->image, NULL, screen, &Sprites[o]->pos);

      }
    }
    SDL_Delay(33);
    SDL_Flip(screen);
  }
  Mix_FreeChunk(son);//Libération du son 1
  Mix_FreeMusic(musique); //Libération de la musique
  Mix_CloseAudio(); //Fermeture de l'API
  SDL_Quit();
  pause = getchar();
  return 0;
}
