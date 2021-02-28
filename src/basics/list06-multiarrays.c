/*
Matrixの計算をする
*/

#include <stdio.h>

void mat_add(const int a[4][3], const int b[4][3], int sum[4][3])
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum[i][j] = a[i][j] + b[i][j];
		}
	}
}

void mat_print(const int mat[4][3])
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%3d", mat[i][j]);
		}
	}
}

int main(void)
{
	int a[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}},
			b[4][3] = {{13, 13, 15}, {16, 17, 18}, {19, 20, 21}, {22, 23, 24}},
			sum[4][3];

	mat_add(a, b, sum);

	puts("The score of the first time.");
	mat_print(a);
	puts("\nThe score of the second time.");
	mat_print(b);
	puts("\nThe sum of two score.");
	mat_print(sum);

	putchar('\n');

	return 0;
}