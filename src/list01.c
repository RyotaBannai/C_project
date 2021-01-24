/*
	誠意数値15と37を加えた結果を表示
*/
#include <stdio.h>

int main(void)
{
	printf("15から37を引いた値は%dです。\n", 15 - 37);
	printf("Hello. \a\n");
	/*\a is escape sequence 拡張表記*/

	int n = 3.14;
	printf("%d\n", n);
	/*This gives you a warning. */

	return 0;
}