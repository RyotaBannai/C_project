/*
 let's try out array in C
*/
#include <stdio.h>

int main(void)
{
	/* 要素数５の配列aを1~5で、bを全て0で初期化 */
	int a[5] = {1, 2, 3, 4, 5}, b[5] = {0}, i;
	/*
	  Cでは配列を代入演算子でコピーできない
		繰り返し文で全要素代入する
	*/
	for (i = 0; i < (sizeof a / sizeof a[0]); i++)
	{
		b[i] = a[4 - i];
	}
	printf("a, b\n");
	for (i = 0; i < (sizeof b / sizeof b[0]); i++)
	{
		printf("%d, %d\n", a[i], b[i]);
	}
}