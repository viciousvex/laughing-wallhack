#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>

#define MAXX 100
#define MAXY 100
#define CHARSIZEX 8
#define CHARSIZEY 8

char screenmem1[MAXY][MAXX];
char screenmem2[MAXY][MAXX];

char a[CHARSIZEY][CHARSIZEX] = {
    ' ','*','*','*','*','*','*',' ',
    '*','*',' ',' ',' ',' ','*','*',
    '*',' ',' ','*','*',' ',' ','*',
    '*',' ','*',' ',' ',' ',' ','*',
    '*',' ','*',' ',' ',' ',' ','*',
    '*',' ',' ','*','*',' ',' ','*',
    '*','*',' ',' ',' ',' ','*','*',
    ' ','*','*','*','*','*','*',' '
};

char printold(char mem[CHARSIZEY][CHARSIZEX], int posx = 0, int posy = 0, float factor = 1.0) {
    
    int roundfact = round(factor);
    
    for (int y=0; y<CHARSIZEY; y++)
        for (int x=0; x<CHARSIZEX; x++) {
            for (int yy=0; yy<roundfact; yy++)
                for (int xx=0; xx<roundfact; xx++) {
                    screenmem1[posy + (y*roundfact) + yy][posx + (x*roundfact) + xx] = mem[y][x];
                }
            }

    return 0;
}

char printscaled(char mem[CHARSIZEY][CHARSIZEX], int posx = 0, int posy = 0, float factor = 1.0) {
    
    for (int y=0; y<CHARSIZEY; y++)
        for (int x=0; x<CHARSIZEX; x++) {
            for (int yy=0; yy<roundfact; yy++)
                for (int xx=0; xx<roundfact; xx++) {
                    screenmem1[posy + (y*roundfact) + yy][posx + (x*roundfact) + xx] = mem[y][x];
                }
        }
    
    return 0;
}

void printmem(char screen[MAXY][MAXX]) {
	int x, y;
	for (y=0; y<MAXY; y++) {
		for (x=0; x<MAXX; x++) {
			mvaddch(y, x, screen[y][x]);
		}
	}
}

void clearmem(char screen[MAXY][MAXX]) {
	int x, y;
	for (y=0; y<MAXY; y++) {
		for (x=0; x<MAXX; x++) {
			screen[y][x] = ' ';
		}
	}
}

void wait(long x) {
    long z=0;
    for (long i=0; i<x; i++) {
        // Just to be doing something.
        z=i*x;
        printf("");
    }
        
}
int main(int argc, char** argv)
{
	WINDOW *mainwin;

	if ((mainwin = initscr()) == NULL) {
		fprintf(stderr, "Error initializing ncurses.\n");
		exit(EXIT_FAILURE);
	}
    nodelay(mainwin, 1);

    clearmem(screenmem1);
    
    while (getch() == ERR) {
        for (int x=0; x<10; x++) {
            printscaled(a, 0, 0, x);
            printmem(screenmem1);
            refresh();
            wait(500000);
            clearmem(screenmem1);
            refresh();
        }
    }
    
	getch();
	
	delwin(mainwin);
	endwin();
	refresh();

	return 0;
}

