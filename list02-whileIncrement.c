/*
 Use postfixd increment operator in while statement
*/
#include <stdio.h>
int main(void){
	int i=10, j;
	while(i-- > 0){
		j = i+1;
		while (j-- > 0){
			putchar('*');
		}
		putchar('\n');
	}
	
	return 0;	
}