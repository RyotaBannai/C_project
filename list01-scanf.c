/*
	読み込んだ整数値をそのまま表示
*/
#include <stdio.h>
int main(void){
	int no;
	
	printf("整数値を入力してください\n");
	scanf("%d", &no);
	
	printf("あなたは%dと入力しました\n", no);
	return 0;	
}