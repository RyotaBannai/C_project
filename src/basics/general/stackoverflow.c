// コアダンプ
#include <stdio.h>

int sum(int n, int m)
{
  if (n == m)
    return n;
  else
    return n + sum(n + 1, m);
}

int main(void)
{
  for (int i = 100; i < 10000000; i *= 10)
    printf("sum(1 ,%d) = %d\n", i, sum(1, i));
  return 0;
  // Segmentation fault: 11
  // 関数 sum は再帰呼び出しが深くなるとスタック領域をはみ出して他の領域を侵すことになるので、Segmentation fault (コアダンプ) が発生
}