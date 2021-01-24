/*
	Checkout the range of variables
*/
#include <stdio.h>
#include <limits.h>

int main(void){
	
	printf("char: %d~%d\n",CHAR_MIN, CHAR_MAX); // char 1byte
	printf("short: %d~%d\n",SHRT_MIN, SHRT_MAX); //short 2byte
	printf("int: %d~%d\n",INT_MIN, INT_MAX); //int 4byte
	printf("long: %ld~%ld\n",LONG_MIN, LONG_MAX); //long 8byte
	// %ld
	
	printf("unsigned: %d~%lu\n",0, ULONG_MAX); //%lu
	// error: use of undeclared identifier 'ULONG_MIN' >> negative range is undeclared for unsigned variables.
	// >> unsigned: 0~18446744073709551615
	return 0;
}