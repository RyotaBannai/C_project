#include <stdio.h>
#include "_enqueue.h"
#include "enqueue.h"
/*
  ライブラリの実体を定義する'実現ファイル'では、ライブラリの内部用の'内部ヘッダ'と、ユーザー向けの'公開ヘッダ'の両方を include する
*/

char __queue[__QUEUE_SIZE];
int __queue_size;
int __front;
int __rear;

int dequeue(void)
{
  if (__queue_size == 0)
    return getchar();
  else
  {
    int temp;
    __queue_size--;
    temp = __queue[__front++];
    if (__front == __QUEUE_SIZE)
      __front = 0;
    return temp;
  }
}