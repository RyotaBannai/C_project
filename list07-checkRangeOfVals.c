/*
	Checkout the range of variables
*/
#include <stdio.h>
#include <limits.h>

int main(void){
	
	printf("char: %d~%d\n",CHAR_MIN, CHAR_MAX);
	printf("int: %d~%d\n",SHRT_MIN, SHRT_MAC);
	printf("int: %d~%d\n",INT_MIN, INT_MAX); // the renge is the same of long on mac
	
	return 0;
}