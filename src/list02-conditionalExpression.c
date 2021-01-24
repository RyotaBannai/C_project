/*
 条件演算子を入れ子で使ってみる
*/
#include <stdio.h>
int main(void){
	
	int a=1,b=2,c=3, max;
	max = a>b? (a>c? a: c): (b>c? b: c);
	printf("一番大きい整数は: %dです。\n", max);

	return 0;	
}