#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *p = malloc(sizeof(int));
  double *q = malloc(sizeof(double));
  int *a = malloc(sizeof(int) * 8);
  if (p == NULL || q == NULL || a == NULL)
    return 1; // 異常終了
  printf("%p\n", p);
  printf("%d\n", *p);
  printf("%p\n", q);
  printf("%f\n", *q);
  printf("%p\n", a);
  for (int i = 0; i < 8; i++)
    printf("%d ", a[i]);
  printf("\n");
  *p = 100;
  *q = 1.2345;
  a[0] = 10;
  a[7] = 80;
  printf("%d\n", *p);
  printf("%f\n", *q);
  for (int i = 0; i < 8; i++)
    printf("%d ", a[i]);
  printf("\n");
  // メモリの解放 (省略してもよい)
  free(p);
  free(q);
  free(a);
  return 0;
}