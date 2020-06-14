Jeu:essai.o AffichageObj.o animate_enemy.o move_enemy.o update_enemy.o update_enemy_state.o 
	gcc essai.o AffichageObj.o animate_enemy.o move_enemy.o update_enemy.o update_enemy_state.o -o Jeu -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm -g

essai.o:essai.c
	gcc -c essai.c -lSDL -lSDL_image -lSDL_mixer -g

animate_enemy.o:animate_enemy.c
	gcc -c animate_enemy.c -lSDL -lSDL_image -lSDL_mixer -g

move_enemy.o:move_enemy.c
	gcc -c move_enemy.c -lSDL -lSDL_image -lSDL_mixer -g

update_enemy.o:update_enemy.c
	gcc -c update_enemy.c -lSDL -lSDL_image -lSDL_mixer -g

update_enemy_state.o:update_enemy_state.c
	gcc -c update_enemy_state.c -lSDL -lSDL_image -lSDL_mixer -g