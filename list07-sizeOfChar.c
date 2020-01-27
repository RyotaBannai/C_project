/*
 checkout of size of char short int.
*/

#include<stdio.h>

int main(void){
	// マックではsizeofの型をunsigned long としている
	// デフォルト通りなら、変換指定では%luを使用
	printf("char:%u\n", (unsigned)sizeof(char)); // >>1
	printf("short:%u\n", (unsigned)sizeof(short)); // >>2
	printf("int:%u\n", (unsigned)sizeof(int)); // >>4
	printf("long:%lu\n", sizeof(long)); // >>8
}