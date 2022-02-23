//
// Created by Adrian on 2/1/2022.
//
#include "colorful.hpp"
int main(){
	puts("this is just a test");
	c_red();
	puts("this is just a test");

	c_blue();
	puts("this is just a test");

	c_green();
	puts("this is just a test");

	c_special(BOLD);
	puts("this is just a test");
	c_reset();
	puts("everything should go back to normal");
	return 0;
}
