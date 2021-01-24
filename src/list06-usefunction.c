/*
 Use function 
*/
#include <stdio.h>

int square(int n){
	return n*n;
}
int pow4(int n){
	return square(square(n));
}
int diff(int a, int b){
	/*Return bigger number*/
	return a>b ? a-b: b-a;
}

int main(void){
	int n1=2, n2=3;
	printf("二乗差は %d　です。\n", diff(square(n1), square(n2)));
	printf("４乗差は %d　です。\n", diff(pow4(n1), pow4(n2)));
}