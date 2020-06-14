
prog:main.o  scrolling.o scroll.o 
	gcc main.o   scrolling.o scroll.o  -o prog -lSDL -lSDL_image -lm -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g
scrolling.o:scrolling.c
	gcc -c scrolling.c -lSDL -lSDL_image -g
scroll.o:scroll.c
	gcc -c scroll.c -lSDL -lSDL_image -g


