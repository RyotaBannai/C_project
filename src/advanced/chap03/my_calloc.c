#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_ELEMS 3

int main(int argc, char const *argv[])
{

  int(*x)[NUMBER_OF_ELEMS];
  int n = 3;

  x = calloc(n * NUMBER_OF_ELEMS, sizeof(int));
  int(*temp)[NUMBER_OF_ELEMS] = x;
  if (x == NULL)
  {
    puts("Failed to allocate memories.");
  }
  else
  {
    for (int i = 0; i < n * NUMBER_OF_ELEMS; i++)
    {
      (*x)[i] = 1;
    }
  }

  for (int i = 0; i < n * NUMBER_OF_ELEMS; i++)
  {
    printf("value is %d, %p \n", (*temp)[i], &(*temp)[i]);
  }
  return 0;
}
