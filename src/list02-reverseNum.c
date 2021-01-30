/*
	Reverse the input number
*/
#include <stdio.h>

int main(void)
{
	int no;
	do
	{
		printf("Plese input positive number: ");
		scanf("%d", &no);
		if (no < 1)
		{
			printf("\aPlease do not input 0 nor negative number.\n");
		}
	} while (no < 1);

	while (no > 0)
	{
		printf("%d", no % 10);
		no /= 10;
	}
	putchar('\n');
}