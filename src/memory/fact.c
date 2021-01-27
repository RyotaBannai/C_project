#include <stdio.h>

int fact(int n)
{
  if (n == 1)
  {
    return;
  }
  else
  {
    return fact(n - 1) * n;
  }
}

void main()
{
  fact(5);
}