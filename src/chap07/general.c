/**/

#include <stdio.h>
#include <math.h>

void test_overflow()
{
  // overflow しない?
  int x, y, z;
  x = 37000;
  y = 30000;
  z = x + y;
  printf("%d", z);
}

void test_lost_precision()
{
  float a = 123456789012345678901234567890.0;
  double b = 123456789012345678901234567890.0;
  long double c = 123456789012345678901234567890.0;
  /*
  a = 123456789182729271864492818432.000000 // 9 桁まで
  b = 123456789012345677877719597056.000000 // 17 桁まで
  c = 123456789012345677877719597056.000000 // 17 桁まで
  */

  printf("a = %f\n", a);
  printf("b = %f\n", b);
  printf("c = %Lf\n", c);
}
double calc_sqrt(double x1, double y1, double x2, double y2)
{
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void test_math_lib()
{
  printf("the distance is %f.\n", calc_sqrt(8, 6, 5, 2));
}
void test_float_loop(void)
{
  // 100 loop 文の誤差が累積し、ちょうど 1.0 にならない
  float x;
  for (x = 0.0; x <= 1.0; x += 0.01)
  {
    printf("%f\n", x);
  }
}

void test_int_loop(void)
{
  // float を使わないで、int を 100.0 で割る（「浮動小数点型（小数部を持つ実数を表す型）」ではなく「整数型」とする）
  // 「整数型」!= 「汎整数型」汎整数型　→ 整数型(short, int, long)、文字型、そして 列挙型 の総称 p170
  float x;
  for (int i = 1; i <= 100; i++)
  {
    x = i / 100.0; // float で割る.「通常の算術型変換（usual arithmetric conversion）」の変換規則に従う. p207
    printf("%f\n", x);
  }
}

int main(void)
{
  test_int_loop();
}