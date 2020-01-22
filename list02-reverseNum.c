/*
	Reverse the input number
*/
#include<stdio.h>

int main(void)
{
	int no;
	do{
		printf("Plese input positive number: ");
		scanf("%d\n" ,$no);
		if(no < 1){
			printf("\aPlease do not input 0 nor negative number.\n")
		}
	}while(no < 1)
}