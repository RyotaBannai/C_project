/* header files */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int n;
  double x;
  int a[3];

  printf("n's address is %p\n", &n); // 処理形態によって表示のされ方は異なるが、osx だと 12 桁の 16 進数
  printf("x's address is %p\n", &x);
  printf("a's address is %p\n", &a);

  // pointer が配列をさすとき（配列の先頭要素）p + 1 は'その後方の要素を指すポインタ'となる
  int i;
  int b[5] = {1.0, 2, 3, 4, 5};
  int *p = b;
  for (i = 0; i < 5; i++)
  {
    printf("&b[%d] = %p p+%d = %p\n", i, &b[i], i, p + i); // + 1 で次のアドレスを参照できるのは、pointer は配列の型情報も保持しているため.
  }
}
