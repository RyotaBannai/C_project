#include <stdio.h>
#include "enqueue.h"
#include "_enqueue.h"

int enqueue(int ch)
{
  if (__queue_size == __QUEUE_SIZE)
    return EOF;
  else
  {
    __queue_size++;
    __queue[__rear++] = ch;
    if (__rear == __QUEUE_SIZE)
      __rear = 0;
    return 1;
  }
}