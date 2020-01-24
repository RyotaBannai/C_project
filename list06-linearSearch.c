/*
	線形探索・番兵法
*/
#include <stdio.h>
#define NUMBER	5 
#define FAILED	-1

int lSearch(int v[], int key, int n){
	int i;
	for(i=0; v[i] != key; i++) // Loop has no procedure to work
		;
	return (i < n) ? i : FAILED;
}

int main(void){
	int i, ky, idx;
	int vx[NUMBER + 1];
	
	printf("%d",NUMBER);
	printf("回文字を入力してください。\n");
	for(i=0; i< NUMBER; i++){
		scanf("%d", &vx[i]);
	}
	putchar('\n');
	
	printf("探したい数字を入力してください。\n");
	scanf("%d", &ky);
	putchar('\n');
	
	vx[NUMBER] = ky; //番兵を入れる

	if((idx = lSearch(vx, ky, NUMBER)) == FAILED) 		printf("数字が見つかりませんでした。\n");
	else
		printf("あなたの見つけたい数字は、一番前の要素から%d要素離れています。\n", idx); 
	
	return 0;
	
}