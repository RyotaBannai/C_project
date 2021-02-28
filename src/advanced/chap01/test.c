#include <stdio.h>
#include <assert.h>
#include "max2X1.h"

/* 
  show all macro of file 
  $ gcc -dM -E test.c
*/

#define DEBUG 0
#if DEBUG == 1
a = x; // プログラムのコメントアウトには #if 指令を使う.
#endif

int main(void)
{
  int max;
  max = max2(1, 2);
  assert(max == 2); // assert には期待値を渡す.
  printf("the bigger value is %d\n", max);
  return 0;
}
