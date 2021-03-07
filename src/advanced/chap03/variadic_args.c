#include <stdio.h>
#include <stdarg.h>

void printf_sum(const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  int arg;
  int sum = 0;
  while ((arg = va_arg(ap, int))) // 可変長引数を取り出し切った後は、NULL が返却される
  {
    sum += arg;
  }
  printf(format, sum);
  va_end(ap);
}

int main(int argc, char const *argv[])
{
  printf_sum("The result is: %d\n", 1, 2, 3);
}
