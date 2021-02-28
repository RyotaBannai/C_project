#include <stdio.h>

int foo(char *mes, int n)
{
  printf("%s\n", mes);
  return n * n;
}

int main(void)
{
  int a = 10, b = 20, c = 30;
  printf("%d %d %d\n", foo("foo", a), foo("bar", b), foo("baz", c));
  return 0;
}
/*
// clang 
foo
bar
baz
100 400 900

// gcc 
foo
bar
baz
100 400 900
*/
