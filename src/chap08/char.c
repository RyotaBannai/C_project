#include <stdio.h>

int main(int argc, char const *argv[])
{
  char zero = '0';
  char one = '1';
  int chs[] = {zero, one, '\0'};

  for (int i = 0; i < sizeof(chs) / sizeof(chs[0]); i++)
  {
    printf("%d\n", chs[i]);
  }
}
