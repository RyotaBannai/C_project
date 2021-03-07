#include <stdio.h>
int main(int argc, char const *argv[])
{
  double d; // 8番地上に確保される
  double *pd;
  char *pc = &d;

  pc++;              // ここで increment されるので非 alignment になる char は 1 byte なので 9 番地上になる（void は 1 byte 境界なので char と同じ）
  pd = (double *)pc; // それによって、double の値が 9 ~ 16 番地で表現される（先頭が切り捨てられる）ようになるので、値が変化してしまう。

  printf("pc = %p\n", pc);
  printf("pd = %p\n", pd);
  return 0;
}
