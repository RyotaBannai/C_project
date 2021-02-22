#include <stdio.h>

int algo(int a, int b)
{
  if (a < 0 || b < 0)
    return 0;
  if (a == b)
    return a;

  int smaller, bigger;
  if (a > b)
  {
    smaller = b;
    bigger = a;
  }
  else
  {
    smaller = a;
    bigger = b;
  }
  printf("smaller: %d bigger%d\n", smaller, bigger);

  int rest;
  for (rest = bigger; rest > smaller; rest -= smaller)
    ;

  printf("rest: %d, smaller: %d\n", rest, smaller);
  if (rest == smaller)
    return rest;
  else
    return algo(rest, bigger);
}

int main(void)
{
  printf("最大公約数 %d\n", algo(18, 12));
}