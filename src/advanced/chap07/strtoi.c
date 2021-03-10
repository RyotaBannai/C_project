#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int strtoi(const char *str, int *err)
{
  int no = 0;
  int sign = 1;
  div_t int_min = div(INT_MIN, 10); // int_min.quot = -21474836, int_min.rem = -8
  // printf("INT_MIN is %d\n", INT_MIN); // -2147483648 on osx
  int_min.rem *= -1; // 符号を反転させる. int_min.rem = 8
  *err = 2;

  while (isspace(*str)) // 先頭の空白を読みとばす
    str++;

  switch (*str)
  {
  case '+': // 正符号
    str++;
    break;
  case '-': // 負符号
    str++;
    sign = -1;
    break;
  }
  // printf("sign is: %d\n", sign);

  for (; isdigit(*str); str++)
  {
    if ((no < int_min.quot) || (no == int_min.quot && *str - '0' > int_min.rem))
    {
      // int_min.quot より小さいすでに小さい場合、次の calculation（no * 10 - (*str - '0')） で INT_MIN を下回る、または
      // int_min.quot と同じでも、remainder よりも小さい値が次の calculation で使われると同じく INT_MIN を下回るので、overflow になる
      no = INT_MIN;
      break;
    }
    no = no * 10 - (*str - '0');
  }

  // 負値で計算しているので、sign が正の場合は符号を反転させる
  if (sign == 1)
  {
    // 実行環境に依存するが、正よりも負の値の方がより広い範囲を表現できるため、正に変換して overflow になったら、表現範囲の最大を返す
    if (no < -INT_MAX)
    {
      no = INT_MAX;
      goto Overflow;
    }
    no = -no;
  }

  *err = *str ? 1 : 0;

Overflow:
  return no;
}

int main(void)
{
  /*
    err:
    0 エラーなし正常終了
    1 変換エラーは無いが、与えられた文字列に数値以外の文字が含まれていたため文字列の通り変換していなく、変換できる部分だけ変換
    2 オーバーフローなどのエラー
  */
  int num, err;
  char buffer[100] = "10000";
  // char buffer[100] = "1000000000000000"; // overflow so shows  -2147483648
  num = strtoi(buffer, &err);
  printf("convert str to int: %d\n", num);
  printf("err: %d\n", err);

  return 0;
}