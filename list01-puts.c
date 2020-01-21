/*
	読み込んだ文字列をputs関数で表示
*/
#include <stdio.h>
int main(void){
	char s[10];
	
	printf("文字列を入力してください: ");
	scanf("%s", s);
	/*文字列を読み取り場合は、第二実引数に&必要なし！*/
	puts(s);

	return 0;	
}