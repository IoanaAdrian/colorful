#ifndef COLORFUL_INCLUDE
#define COLORFUL_INCLUDE

/////////////////////////
#include <stdio.h>
/////////////////////////

#define ESC 0x1B

// attribute
#define RESET		0
#define BRIGHT 		1
#define DIM		2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8
// fg += 30; bg+= 40
#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7
// special
#define BOLD 1
#define ITALIC 3
/////////////////////////

void c_color(int attr, int fg, int bg);
void c_special(int sp);
void c_reset();

void c_red();
void c_blue();
void c_green();

/////////////////////////

void c_color(int attr, int fg, int bg){
	printf("%c[%i;%i;%im",ESC,attr,fg+30,bg+40);	
}

void c_special(int sp){
	c_reset();
	printf("%c[%im",ESC,sp);
}

void c_reset(){
	c_color(RESET,WHITE,BLACK);
}

void c_red(){
	c_color(BRIGHT,RED,BLACK);
}
void c_blue(){
	c_color(BRIGHT,BLUE,WHITE);
}
void c_green(){
	c_color(BRIGHT,GREEN,BLACK);
}

#endif


