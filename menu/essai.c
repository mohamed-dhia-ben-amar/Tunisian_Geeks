/**
* @file essai.c
* @brief Testing Program.
* @author Tunisian Geeks
* @version 1.0
* @date Jun 14 2020
*
* Testing program for 2d game
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "tache.h"
#include "scrolling.c"
#include "quiz.c"
#include "game.h"

typedef struct _s
{

  SDL_Surface *image;
  SDL_Surface *hoverImage;
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

Sprite *Sprites[100];
int nSprites = 0;
int gameRunning = 1;
int cMouseOver = -1;
int mouseDown = 0;
int processedClick = 0;

Sprite *MakeSprite(char name[], int type)
{
  char fname[40] = "";
  strcpy(fname, name);
  strcat(fname, ".bmp");
  Sprite *sprite = malloc(sizeof(Sprite));
  sprite->image = SDL_LoadBMP(fname);
  SDL_SetColorKey(sprite->image, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->image->format, 0, 0, 0));
  sprite->visible = 1;
  sprite->type = type;
  sprite->clickEvent = 0;
  if (type == 1)
  {
    char hname[30] = "";
    strcat(hname, name);
    strcat(hname, " hover.bmp");
    sprite->hoverImage = SDL_LoadBMP(hname);
    SDL_SetColorKey(sprite->hoverImage, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->hoverImage->format, 0, 0, 0));
  }
  Sprites[nSprites++] = sprite;
  return sprite;
}

void checkMouse()
{
  cMouseOver = -1;
  int mx, my;
  SDL_GetMouseState(&mx, &my);
  for (int o = nSprites - 1; o >= 0; o--)
  {
    if (Sprites[o]->pos.x <= mx && Sprites[o]->pos.y <= my && Sprites[o]->pos.x + Sprites[o]->pos.w >= mx && Sprites[o]->pos.y + Sprites[o]->pos.h >= my)
    {
      cMouseOver = o;
      break;
    }
  }
}

Sprite *addButton(char name[], int x, int y)
{
  Sprite *btn = MakeSprite(name, 1);
  btn->pos.x = x;
  btn->pos.y = y;
  btn->pos.w = 100;
  btn->pos.h = 27;

  return btn;
}

Sprite *addButton2(char name[], int x, int y)
{
  Sprite *btn = MakeSprite(name, 0);
  btn->pos.x = x;
  btn->pos.y = y;
  btn->pos.w = 100;
  btn->pos.h = 27;

  return btn;
}

void processClickEvent(int e)
{
  if (e % 2 == 0)
    /*Sprites[0]->image = SDL_LoadBMP("ICON.bmp")*/;
  if (e % 2 != 0)
    /*Sprites[0]->image = SDL_LoadBMP("bg.bmp")*/;
}
void processexitEvent(int e)
{
  switch (e)
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
  SDL_Surface *text = NULL;
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

const char *getQuestion(Question *t, int q)
{
  if (q == 0)
    return t->reponse1;
  if (q == 1)
    return t->reponse2;
  return t->reponse3;
}

int main()
{
  int test_menu = 0;
  int test = 1, gamma = -1;
  int volume;
  SDL_Delay(1000);
  SDL_Surface *screen;
  char pause;
  SDL_Surface *msg, *arrow;
  TTF_Font *font = NULL;
  //texte(screen);
  //song
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
  {
    printf("%s", Mix_GetError());
  }
  Mix_Music *musique = NULL; //Création du pointeur de type Mix_Music
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
  musique = Mix_LoadMUS("Misplaced");            //Chargement de la musique
  Mix_PlayMusic(musique, -1);                    //Jouer infiniment la musique
                                                 //son bref
  Mix_AllocateChannels(32);                      //Allouer 32 canaux
  Mix_Volume(1, MIX_MAX_VOLUME / 2);             //Mettre à mi-volume le post 1
  Mix_Chunk *son;                                //Créer un pointeur pour stocker un .WAV
  son = Mix_LoadWAV("son.wav");                  //Charger un wav dans un pointeur
  Mix_VolumeChunk(son, MIX_MAX_VOLUME * 250000); //Mettre un volume pour ce wav

  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("Unable to initialize SDL: %s\n", SDL_GetError());
    return 1;
  }
  screen = SDL_SetVideoMode(1582, 704, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen == NULL)
  {
    printf("Unable to set video mode : %s\n", SDL_GetError());
    return 1;
  }
  Sprite *bg = MakeSprite("bg", 0);
  bg->pos.x = 0;
  bg->pos.y = 0;
  bg->pos.w = 800;
  bg->pos.h = 480;
  Sprite *contBtn = addButton("play1", 1000, 120);
  contBtn->clickEvent = 1;
  Sprite *contBtn5 = addButton("settings", 1100, 240);
  contBtn5->ShowMenu = 1;
  addButton("scoreboard1", 1000, 360);
  addButton("credits1", 1100, 480);
  Sprite *contBtn2 = addButton("quit11", 1000, 600);
  contBtn2->exitEvent = 1;
  SDL_Delay(1000);
  while (gameRunning == 1)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        gameRunning = 0;
      }

      else if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN)
      {
        mouseDown = 1;
      }
      else if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONUP)
      {
        mouseDown = 0;
        processedClick = 0;
      }
      else if (event.key.keysym.sym == SDLK_UP)
      {
        gamma++;
        SDL_BlitSurface(Sprites[gamma]->hoverImage, NULL, screen, &Sprites[gamma]->pos);
        SDL_Delay(1000);
        printf("%d\n", gamma);
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
    for (int o = 0; o < nSprites; o++)
    {
      if (Sprites[o]->visible != 1)
        continue;
      if (Sprites[o]->type == 1 || Sprites[o]->type == 0)
      {
        if (cMouseOver == o)
        {
          if (mouseDown == 1)
          {
            if (processedClick == 0)
            {
              Mix_PlayChannel(1, son, 0);
            }
            if (processedClick == 0 && Sprites[o]->clickEvent == 1)
            {
              SDL_Surface *screen;
              int mv = 6; /*vitesse de scrolling*/
              screen = SDL_SetVideoMode(1600, 240, 32, SDL_HWSURFACE);
              SDL_Event event;
              SDL_Surface *fond = NULL;

              int b = 0, i;

              SDL_Rect positionfond;
              SDL_Rect animepos[8];
              SDL_Rect positionrel;
              SDL_Rect positionabs;

              int frame = 4;
              Hero hero;
              initializeHero(&hero);
              animepos[0].x = 0;
              animepos[0].y = 0;
              animepos[0].w = 128;
              animepos[0].h = 180;

              animepos[1].x = 128;
              animepos[1].y = 0;
              animepos[1].w = 109;
              animepos[1].h = 180;

              animepos[2].x = 237;
              animepos[2].y = 0;
              animepos[2].w = 167;
              animepos[2].h = 180;

              animepos[3].x = 404;
              animepos[3].y = 0;
              animepos[3].w = 130;
              animepos[3].h = 180;

              animepos[4].x = 554;
              animepos[4].y = 0;
              animepos[4].w = 147;
              animepos[4].h = 180;

              animepos[5].x = 681;
              animepos[5].y = 0;
              animepos[5].w = 129;
              animepos[5].h = 180;

              animepos[6].x = 700;
              animepos[6].y = 0;
              animepos[6].w = 130;
              animepos[6].h = 180;

              animepos[7].x = 967;
              animepos[7].y = 0;
              animepos[7].w = 159;
              animepos[7].h = 180;

              positionfond.x = 0;
              positionfond.y = 0;

              scrollImage img;
              SCROLL_Init(&img, "map.png");

              SDL_EnableKeyRepeat(1, 1); /*pour saisir multiple touche*/

              while (gameRunning)
              {
                while (SDL_PollEvent(&event))
                {
                  if (event.type == SDL_QUIT)
                    gameRunning = 0;
                  if (event.type == SDL_KEYDOWN)
                  {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                      gameRunning = 0;
                    if (event.key.keysym.sym == SDLK_RIGHT)
                    {

                      if (hero.positionabs.x < 1001)
                      {
                        hero.positionabs.x += 12;
                        printf("abs.x = %d .\n", hero.positionabs.x);
                      }

                      if (hero.positionabs.x > 1000)
                      {
                        img.clip.x += mv;
                      }

                      animed(animepos, &frame);
                    }
                    if (hero.positionabs.x == 600) //position of engigmas appiration
                    {
                      int tempsPrecedent = 0, tempsActuel = 0;
                      //	Question a;
                      //	strcpy(a.question,"hello");

                      int running = 1;

                      int currentChoice = 0;
                      srand(time(NULL)); //initialise fct sur le temps actuel
                      int qid = (int)(random() % 5);
                      int choices[3] = {0, 1, 2};
                      for (int i = 0; i < 10; i++)
                      {
                        int t = random() % 3;
                        int t2 = random() % 3;
                        int t3 = choices[t];
                        choices[t] = choices[t2];
                        choices[t2] = t3;
                      }

                      printf("%d %d %d\n", choices[0], choices[1], choices[2]); //donne des valeurs aleatoires entre 0 et 2

                      Quiz q; //fichier
                      QUIZ_Init(&q, "./questions.txt");

                      SDL_Surface *sc, *msg, *arrow;
                      TTF_Font *font = NULL;

                      SDL_Init(SDL_INIT_EVERYTHING); //initialiser sdl
                      TTF_Init();

                      sc = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE);

                      SDL_Event event;

                      font = TTF_OpenFont("font.ttf", 24);

                      SDL_Color color = {255, 255, 255};

                      SDL_Rect rect;
                      SDL_Rect choice;

                      choice.x = 150;
                      choice.y = 50;

                      arrow = SDL_CreateRGBSurface(0, 16, 16, 32, 0, 0, 0, 0); //creer une surface
                      SDL_FillRect(arrow, NULL, SDL_MapRGB(arrow->format, 255, 255, 255));

                      SDL_EnableKeyRepeat(0, 0);

                      while (running)
                      {
                        while (SDL_PollEvent(&event))
                        {
                          if (event.type == SDL_QUIT)
                          {
                            running = 0;
                          }
                          if (event.type == SDL_KEYDOWN)
                          {
                            if (event.key.keysym.sym == SDLK_ESCAPE)
                            {
                              running = 0;
                            }
                            if (event.key.keysym.sym == SDLK_DOWN)
                            {
                              if (currentChoice != 2)
                                currentChoice++;
                              else
                                currentChoice = 0;
                            }
                            if (event.key.keysym.sym == SDLK_UP)
                            {
                              if (currentChoice != 0)
                                currentChoice--;
                              else
                                currentChoice = 2;
                            }
                            if (event.key.keysym.sym == SDLK_RETURN)
                            {

                              if (choices[currentChoice] == 0)
                              {
                                running = 0;
                                SDL_Rect t;
                                t.x = 300;
                                t.y = 400;
                                msg = TTF_RenderText_Solid(font, "Correct Answer", color);
                                SDL_BlitSurface(msg, NULL, sc, &t);
                                SDL_Flip(sc);
                                SDL_Delay(1000);
                              }
                              else
                              {
                                running = 0;
                                SDL_Rect t;
                                t.x = 300;
                                t.y = 400;
                                msg = TTF_RenderText_Solid(font, "Incorrect Answer", color);
                                SDL_BlitSurface(msg, NULL, sc, &t);
                                SDL_Flip(sc);
                                SDL_Delay(1000);
                              }
                            }
                          }
                          tempsActuel = SDL_GetTicks();
                          if (tempsActuel - tempsPrecedent > 5000) /* Si 4000 ms se sont écoulées depuis le dernier tour de boucle */
                          {
                            running = 0;
                          }
                        }

                        SDL_FillRect(sc, &sc->clip_rect, 0x000000);

                        rect.x = 200;
                        rect.y = 0;

                        msg = TTF_RenderText_Solid(font, q.questions[qid].question, color);
                        SDL_BlitSurface(msg, NULL, sc, &rect);

                        // 1,2,0 4.2.3

                        rect.y = 50 + 50 * 0;
                        msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid], choices[0]), color);
                        SDL_BlitSurface(msg, NULL, sc, &rect);

                        rect.y = 50 + 50 * 1;
                        msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid], choices[1]), color);
                        SDL_BlitSurface(msg, NULL, sc, &rect);

                        rect.y = 50 + 50 * 2;
                        msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid], choices[2]), color);
                        SDL_BlitSurface(msg, NULL, sc, &rect);
                        choice.y = 50 + currentChoice * 50;
                        SDL_BlitSurface(arrow, NULL, sc, &choice);

                        SDL_Flip(sc);
                        SDL_Delay(16);
                      }

                      SDL_FreeSurface(sc);
                      SDL_FreeSurface(msg);
                      TTF_CloseFont(font);
                    }

                    if (event.key.keysym.sym == SDLK_LEFT)
                    {
                      if (img.clip.x > 0)
                      {
                        img.clip.x -= mv;
                      }
                      animeg(animepos, &frame);
                      hero.positionabs.x -= 12;
                    }
                    if (event.key.keysym.sym == SDLK_UP)
                    {
                      // EVOLUTION
                      //On avance de 1
                      positionrel.x++;
                      if (positionrel.x >= 50)
                      {
                        positionrel.x = -50;
                      }
                      //On met à "0" les pos abs:
                      positionabs.x = 200;
                      positionabs.y = 300 - /*hero.h*/ 30;

                      //On calcule la valeur relative de y:
                      positionrel.y = (-0.04 * (positionrel.x * positionrel.x) + 100);

                      //On calcule maintenant les valeurs abs
                      positionabs.x = positionabs.x + positionrel.x + 50;
                      positionabs.y = positionabs.y - positionrel.y;
                    }
                  }
                }

                SCROLL_Render(&img, &screen); /*bliter l'image du background dans sa nouvelle position */
                SDL_BlitSurface(fond, NULL, screen, &positionfond);
                SDL_BlitSurface(hero.image, &animepos[frame], screen, &hero.positionabs);
                SDL_Delay(16);
                SDL_Flip(screen);
              }

              SDL_FreeSurface(fond);
            }

            if (processedClick == 0 && Sprites[o]->exitEvent == 1)
            {
              processexitEvent(Sprites[o]->exitEvent);
            }
            if (processedClick == 0 && Sprites[o]->MinusEvent == 1)
            {
              // down volume code here
            }
            if (processedClick == 0 && Sprites[o]->PlusEvent == 1)
            {
              // up volume code here
            }
            if (processedClick == 0 && Sprites[o]->ShowMenu == 1)
            {
              SDL_Surface *screen2 = screen;
              Sprite *sett_menu = addButton2("settings_menu", 200, 200);
              sett_menu->hoverImage = sett_menu->image;
              SDL_BlitSurface(sett_menu->image, NULL, screen2, &sett_menu->pos);
              Sprite *contBtn3 = addButton("minus", 440, 320);
              contBtn3->MinusEvent = 1;
              Sprite *contBtn4 = addButton("plus", 550, 320);
              contBtn4->PlusEvent = 1;
              Sprite *contBtn5 = addButton("off_fs", 440, 480);
              contBtn5->fs = 0;
              Sprite *contBtn6 = addButton("on_fs", 550, 480);
              contBtn6->fs = 1;
            }
            if (processedClick == 0 && Sprites[o]->fs == 1)
            {
              screen = SDL_SetVideoMode(bg->pos.x, bg->pos.x, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
            }
            if (processedClick == 0 && Sprites[o]->fs == 0)
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
  Mix_FreeChunk(son);     //Libération du son 1
  Mix_FreeMusic(musique); //Libération de la musique
  Mix_CloseAudio();       //Fermeture de l'API
  SDL_FreeSurface(screen);
  SDL_FreeSurface(msg);
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
  pause = getchar();
  return 1;
}
