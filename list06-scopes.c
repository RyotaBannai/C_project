/*
	Understanding scopes in c
*/
#include <stdio.h>

int x=100; // file scope

void print_x(void){
	printf("in print_x function: %3d\n",x);
}
int main(void){
	int i, x=x; // main block // Be aware of this. the right side of x is not x from file scipe. the x is from left side x, however, this statement is not complete when it's called. 
	print_x();
	printf("main func scope: %3d\n",x);
	
	for (i=1;i<5;i++){
		int x=1; // for block
		printf("%3d",x+i);
	}
	putchar('\n');
	printf("main func scope: %3d\n",x);
	return 0;
}