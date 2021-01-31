#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void)
{
  int x = 10;
  int y = 20;
  swap(&x, &y); // & 演算子を使ってその変数のアドレスを渡す
  printf("x = %d\ny = %d\n", x, y);
  return 0;
}