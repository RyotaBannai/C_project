#include <stdio.h>
#include <stdlib.h>

/*
  s->ptr は常に最大数のひとつ大きい値を指す
*/

typedef struct
{
  int max;  // max elements of stack
  int ptr;  // the pointer of stack
  int *stk; // the body of stack
} Stack;

// initialize new stack
int StackAlloc(Stack *s, int max)
{
  s->ptr = 0;
  // The fail of allocate memory for stack..
  if ((s->stk = calloc(max, sizeof(int))) == NULL)
  {
    s->max = 0;
    return -1;
  }
  s->max = max;
  return 0;
}

int StackPush(Stack *s, int elem)
{
  if (s->ptr >= s->max)
  {
    return -1;
  }
  s->stk[s->ptr++] = elem;
  return 0;
}

int StackPop(Stack *s, int *value)
{
  if (s->ptr <= 0)
  {
    return -1;
  }
  *value = s->stk[--s->ptr];
  return 0;
}

int StackPeek(const Stack *s, int *value)
{
  if (s->ptr <= 0)
  {
    return -1;
  }
  *value = s->stk[s->ptr - 1];
  return 0;
}

int StackSize(const Stack *s)
{
  // returns current Stack size.
  return s->ptr;
}

int StackCap(const Stack *s)
{
  // returns Stack capacity
  return s->max;
}

int StackIsEmpty(const Stack *s)
{
  // returns if true if Stack is empty, otherwise false
  return s->ptr <= 0;
}

int StackIsFull(const Stack *s)
{
  return s->ptr == s->max;
}

void StackClear(Stack *s)
{
  // clears Stack
  s->ptr = 0;
}

int main(void)
{
  Stack stk;
  if (StackAlloc(&stk, 5) == -1)
  {
    printf("Fails to allocate Stack\n");
  }

  while (1)
  {
    int opt, num;
    char elem[100];
    printf("The number of current data size: %d\nThe stack capacity is: %d\n", StackSize(&stk), StackCap(&stk));
    printf("1. push, 2. pop, 0. end: ");

    scanf("%d", &opt); // infinite loop with str input
    if (opt == 0)
      break;

    switch (opt)
    {
    case 1:
      scanf("%s", elem);
      num = atoi(elem);
      printf("data is: %d\n", num);
      if (StackPush(&stk, num) == -1)
        printf("failed to push..\n");
      break;
    case 2:
      if (StackPop(&stk, &num) == -1)
        printf("failed to pop..\n");
      else
        printf("the value is %d\n", num);
      break;
    }
  }
  StackClear(&stk);
  return 0;
}
