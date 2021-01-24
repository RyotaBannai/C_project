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
	
	//what about int array
	int array[2]={0};
	printf("the size of whole array is %d, because int(=4byte) * 2 (elements in array)\n", (unsigned)sizeof array);
	double a;
	printf("double: %d\n", (unsigned)sizeof a); // >> 8 same as long
	
	//evaluate statement 
	printf("evaluate statement 1: %d\n", (unsigned)sizeof 1); // >>4
	printf("evaluate statement unsigned -1(=%d): %d\n", (unsigned)-1, (unsigned)sizeof (unsigned)-1); // >>3?
	//負があったほうが処理が楽だったり、負になる可能性のあるものをunsignedで定義するのはバグの元。unsignedは加算減算・除乗算しないものやビット演算するものだけに限定すべき。
	
	return 0;
}