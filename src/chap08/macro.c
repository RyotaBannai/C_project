#include <stdio.h>

#define sqr(x) ((x) * (x)) // 関数形式マクロ
#define swap(a, b)           \
  {                          \
    typeof(a) ttttttttt = a; \
    a = b;                   \
    b = ttttttttt;           \
  }

#define puts_alert(str) (putchar('\a'), puts(str)) // コンマ演算子を使う

// https://stackoverflow.com/questions/2637856/is-there-a-built-in-way-to-swap-two-variables-in-c

int main(void)
{
  printf("int 型整数の２乗 %d\n", sqr(2));
  printf("double 型整数の２乗 %f\n", sqr(2.0));

  int a = 1;
  int b = 2;
  swap(a, b);
  // printf("%s", typeof(a));
  printf("first %d, second %d\n", a, b);

  int n = 1;
  if (n)
    puts_alert("value is 1");
  else
    puts_alert("value is 0");
}