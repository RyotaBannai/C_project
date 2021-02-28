#include <stdio.h>
#define LEN_ARR(x) (sizeof(x) / sizeof((x)[0])) // macro

int fact(int n)
{
  if (n == 1)
  {
    return 1;
  }
  else
  {
    return fact(n - 1) * n;
  }
}

int main()
{
  // fact(5);
  int array[10], n, *p;
  for (n = 0, p = array; n < 10; ++n)
  {
    *p++ = 0;
  }

  int size_array = LEN_ARR(array);
  for (n = 0; n < size_array; ++n)
  {
    printf("%d ", array[n]);
  }
}