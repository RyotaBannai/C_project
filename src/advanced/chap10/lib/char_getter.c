#include <stdio.h>
#include <ctype.h>
#include "enqueue.h"

/*
  compile ->
  $gcc dequeue.c enqueue.c char_getter.c

  ・このプログラムは queue size == 1 あれば機能する
*/
int get_num(void)
{
  int c = 0;
  int x = 0;
  int ch; // 一文字

  // 呼び出し元で loop しているため、123abc456 の abc456 は次の回で dequeue される
  for (; (ch = dequeue()) != EOF && isdigit(ch); c++)
    x = x * 10 + ch - '0'; // 通常の文字 → 数値変換

  if (ch != EOF)
    enqueue(ch); // a は戻す

  if (c)
    printf("%d\n", x); // 取得結果を表示
  return ch;
}

int get_non_num(void)
{
  int ch; // 一文字

  while ((ch = dequeue()) != EOF && !isdigit(ch))
    putchar(ch);

  if (ch != EOF)
    enqueue(ch); // 4 は戻す

  putchar('\n');
  return ch;
}

int main(void)
{
  while (get_num() != EOF)
    if (get_non_num() == EOF)
      break;

  return 0;
}