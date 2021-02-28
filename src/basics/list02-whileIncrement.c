/*
 Use postfixd increment operator in while statement
 後置は変化前の値、前置は変化後の値
*/
#include <stdio.h>
int main(void)
{
	int i = 10, j;
	while (i-- > 0)
	{
		j = i + 1;
		while (j-- > 0)
		{
			putchar('*');
		}
		putchar('\n');
	}
	/* while for do or while for while? -> use Compound Statement*/
	i = 0;
	do
	{
		++i;
	} while (i < 5);
	while (i >= 0)
		printf("%d\n", i--);

	return 0;
}