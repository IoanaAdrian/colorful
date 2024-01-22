#include "colorful.h"
int main(){
	printf("normal looking text\n");

	c_red();
	printf("red text on a black background");
	c_nlreset();

	c_blue();
	printf("blue text on a white background");
	c_nlreset();

	c_green();
	printf("green text on a black background");
	c_nlreset();

	c_special(C_BOLD);
	printf("bold text");
	c_nlreset();

	c_rainbow("rainbow text rainbow text rainbow text rainbow text");
	c_nlreset();

	printf("everything should go back to normal\n");
	return 0;
}
