/*
Matrix outer -> x*y * y*x -> x*x
*/

#include <stdio.h>

void mat_mul(const int a[4][3], const int b[3][4], int mul[4][4])
{
	int i, j, k, temp;
	for (i = 0; i < 4; i++)
	{ //a
		for (j = 0; j < 4; j++)
		{						//b
			temp = 0; // initialize
			for (k = 0; k < 3; k++)
			{
				temp += a[i][k] * b[k][j];
			}
			mul[i][j] = temp;
		}
	}
}

void mat_print(const int mat[4][4])
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%6d", mat[i][j]);
		}
		putchar('\n');
	}
}

int main(void)
{
	int a[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}},
			b[3][4] = {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}},
			mul[4][4];

	mat_mul(a, b, mul);
	puts("\nThe mul of two score.");
	mat_print(mul);
	printf("The first element of matrix should be: %d", (1 * 13) + (2 * 17) + (3 * 21));

	putchar('\n');

	return 0;
}