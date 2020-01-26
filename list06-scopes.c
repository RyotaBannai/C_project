/*
	Understanding scopes in c
*/
#include <stdio.h>

int x=100; // file scope

void print_x(void){
	printf("%3d",x);
}
int main(void){
	int i, x=1; // main block
	print_x();
	printf("%3d",x);
	
	for (i=1;i<5;i++){
		int x=1; // for block
		printf("%3d",x+i);
	}
	
	printf("\n%3d\n",x);
	return 0;
}