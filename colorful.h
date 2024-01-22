#ifndef COLORFUL_INCLUDE
#define COLORFUL_INCLUDE

/////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////

#define C_ESC 0x1B // equivalent to \033 ANSI escape code

// attribute
#define C_RESET		0x0
#define C_BRIGHT 	0x1
#define C_DIM		0x2
#define C_UNDERLINE 0x3
#define C_BLINK		0x4
#define C_REVERSE	0x7
#define C_HIDDEN	0x8
// dark colors
// fg += 30; bg+= 40
#define C_DBLACK 	0x0
#define C_DRED		0x1
#define C_DGREEN	0x2
#define C_DYELLOW	0x3
#define C_DBLUE		0x4
#define C_DMAGENTA	0x5
#define C_DCYAN		0x6
#define	C_DWHITE	0x7
// bright colors
// fg += 82; bg += 92
#define C_BBLACK 	0x8
#define C_BRED		0x9 
#define C_BGREEN	0xA
#define C_BYELLOW 	0xB
#define C_BBLUE		0xC
#define C_BMAGENTA 	0xD
#define C_BCYAN		0xE
#define C_BWHITE 	0xF 
// special
#define C_BOLD 		1
#define C_ITALIC 	3
///////////////////////// START_Declarations
int calc_fg(int color);
int calc_bg(int color);

void c_color(int attr, int fg, int bg);
void c_special(int sp);
void c_reset();
void c_nlreset();

void c_red();
void c_blue();
void c_green();

void c_rainbow(const char *str);
void seed_rand();

///////////////////////// END_Declarations

///////////////////////// START_Implementations

int calc_fg(int color){
	return (color < 8) ? color + 30 : color + 82;
}

int calc_bg(int color){
	return (color < 8) ? color + 40 : color + 92;
}

void seed_rand(){
	static int ok = 0;
	if(ok==0){
		srand(time(NULL));
		ok = 1;
	}
}

void c_rainbow(const char *str){
	seed_rand();

	int len = strlen(str);
	for(int i=0;i<len;i++){
		int fg_color = rand() % (C_BWHITE + 1);
		//int bg_color = rand() % (C_BWHITE + 1);
		int bg_color = C_DBLACK;
		c_color(C_BRIGHT, fg_color, bg_color);
		fputc(str[i], stdout);
		c_reset();
	}
}

void c_color(int attr, int fg, int bg){
	printf("%c[%i;%i;%im", C_ESC, attr, calc_fg(fg), calc_bg(bg));	
}

void c_special(int sp){
	c_reset();
	printf("%c[%im",C_ESC,sp);
}

void c_reset(){
	printf("%c[%im",C_ESC, C_RESET);
}

void c_nlreset(){
	printf("%c[%im\n",C_ESC, C_RESET);
}

void c_red(){
	c_color(C_BRIGHT, C_DRED, C_DBLACK);
}
void c_blue(){
	c_color(C_BRIGHT, C_DBLUE, C_DWHITE);
}
void c_green(){
	c_color(C_BRIGHT, C_DGREEN, C_DBLACK);
}

///////////////////////// END_Implementations

#endif


