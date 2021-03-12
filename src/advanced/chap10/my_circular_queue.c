#include <stdio.h>

#define QUEUE_SIZE 10;

char queue[QUEUE_SIZE];
int queue_size = 0;
int front = 0;
int rear = 0;

int enqueue(int ch)
{
  if (queue_size == QUEUE_SIZE) // 以上入らない
    return EOF;                 // fail
  else
  {
    queue_size++;
    queue[rear++] = ch;
    if (rear == QUEUE_SIZE)
      rear = 0;
    return 1; // success
  }
}

int dequeue(void)
{
  if (queue_size == 0)
    // queue に何も入っていない場合は、標準入力からデータを受け付ける
    return getchar();
  else
  {
    int temp;
    queue_size--;
    temp = queue[front++];
    if (front == QUEUE_SIZE) // 循環構造なので QUEUE_SIZE と同じと言うことは、先頭であると考えることができる
      front = 0;
    return temp;
  }
}