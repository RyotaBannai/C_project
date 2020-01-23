/*
	引数を受け取らない関数にはvoidを明示する
*/
#include <stdio.h>

int scan_pint(void){
	int temp;
	do{
		printf("非負の整数を入力してください。:");
		scanf("%d",&temp);
		if (temp <= 0) puts("\a正でない整数を入力しないでください。");
	}while(temp <= 0);
	
	return temp;
}
int rev_int(int num){
	int temp = 0;
	do{
		temp = temp*10 + num%10; //tempの桁を上げる＆一の桁に加える
		num /=10; //桁を下げる
	}while (num > 0);
	
	return temp;
}
void hello(void){
	puts("今日わ.");
}

int main(void){
	hello();
	int num = scan_pint();
	printf("入力した数値を反転させました: %d\n", rev_int(num));
}