#include <stdio.h>
#include <limits.h>
/*
  src/general/bits.c
*/

int count_bits(unsigned x)
{
  int bits = 0;
  while (x)
  {
    if (x & 1U)
      bits++;
    x >>= 1;
  }
  return bits;
}

int int_bits(void)
{
  return count_bits(~0U);
}

void print_bits(unsigned x)
{
  int i;
  for (i = int_bits() - 1; i >= 0; i--)
    putchar(((x >> i) & 1U) ? '1' : '0');
  putchar('\n');
}

int main(int argc, char const *argv[])
{
  int a = -1;
  unsigned b = 1;
  int result1 = a < b;
  int result2 = a < (int)b;
  int result3 = (unsigned)a < b;

  printf("result1 is %s\n", result1 == 1 ? "true" : "false"); // false
  printf("result2 is %s\n", result2 == 1 ? "true" : "false"); // true

  print_bits(b);           // 00000000000000000000000000000001
  print_bits((unsigned)a); // 11111111111111111111111111111111 2's complement representation.

  //
  int x;
  signed char ch = CHAR_MAX;
  printf("%d\n", ch);
  x = ch + 1;
  printf("%d\n", x);
  x = ++ch;
  printf("%d\n", x);
  x = ++ch;
  printf("%d\n", x);
#if 0
  /*
  results:...
  127
  128
  -128
  -127
  */
#endif
  return 0;
}
