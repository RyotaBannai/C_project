#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  printf("the size of void * is %lu\n", sizeof(void *)); // 8
  printf("the size of char * is %lu\n", sizeof(char *)); // 8
  printf("the size of int * is %lu\n", sizeof(int *));   // 8
  printf("the size of void is %lu\n", sizeof(void));     // 1
  printf("the size of char is %lu\n", sizeof(char));     // 1
  printf("the size of int is %lu\n", sizeof(int));       // 4
  printf("the size of long is %lu\n", sizeof(long));     // 8
  return (EXIT_SUCCESS);
}
