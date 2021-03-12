#include <stdio.h>
#include "enqueue.h"
#include "_enqueue.h"

extern char __queue[__QUEUE_SIZE];
extern int __queue_size;
extern int __front;
extern int __rear;

int dequeue(void)
{
  if (__queue_size == 0)
    return getchar();
  else
  {
    int temp;
    __queue_size--;
    temp = queue[front++];
    if (__front == __QUEUE_SIZE)
      __front = 0;
    return temp;
  }
}