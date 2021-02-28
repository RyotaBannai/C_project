#include <stdio.h>

/*
  Useful functions.
*/

int count_bits(unsigned x) // 孫請け請け of print_bits
{
  int bits = 0;
  while (x)
  {
    if (x & 1U) // 1U == 00000000000000000000000000000001
      bits++;
    x >>= 1;
  }
  return bits;
}

int int_bits(void) // 下請け of print_bits
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

void print_bool(int value)
{
  printf("%s\n", value == 1 ? "true" : "false");
}

void check_if_odd(unsigned value)
{
  printf("this value is odd? %s\n", (value & 1) == 1 ? "true" : "false");
}

int main(void)
{
  // unsigned a = 1963;
  // unsigned b = 12345;
  unsigned one = 1;
  unsigned four = 4;

  // bits
  print_bits(~0U);
  print_bits(one);
  print_bits(one & ~0U);
  print_bits(four);
  print_bits(four & ~0U);

  // bool
  print_bool(one & four); // false
  print_bool(one & 1U);   // true
  print_bool(four & 1U);  // false
  printf("%d\n", four & 1U);
  // https://stackoverflow.com/questions/17307275/what-is-the-printf-format-specifier-for-bool
  // https://stackoverflow.com/questions/37291681/does-the-c-standard-explicitly-indicate-truth-value-as-0-or-1

  check_if_odd(one);
  check_if_odd(four);
  if (four)               // && 0)
    printf("%s\n", "OK"); // any positive or negative value except 0 is true.
  else
    printf("%s\n", "ERR");

  return 0;
}