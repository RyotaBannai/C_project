/*
*/
#include <stdio.h>
int main(void)
{
	int n;
	double f;

	printf("整数値入力してください: ");
	scanf("%d", &n);
	printf("最も下の桁は：%dです\n", n % 10);

	printf("整数または、浮動小数点数を入力してください: ");
	scanf("%lf", &f);
	printf("あなたが入力した数値は：%fです\n", f);

	return 0;
}