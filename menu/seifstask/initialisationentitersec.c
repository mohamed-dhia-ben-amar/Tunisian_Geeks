void init_ennemi2(int n) {
  ennemi e[10];
  int i;
  for (i = 0; i < n; i++) {
    strcat(e[i].nom_img_ennemi, ".bmp");
    e[i].img = SDL_LoadBMP(e[i].nom_img_ennemi);
    e[i].pos_img.x = rand()%30+1;
    srand(30);
    e[i].pos_img.y = 500;//à regler apres la finalisation du jeu
    e[i].pos_img.w = e[i].img->w;
    e[i].pos_img.h = e[i].img->h;
  
  }
}
