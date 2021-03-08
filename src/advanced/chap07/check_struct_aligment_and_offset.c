#include <stdio.h>
#include <stddef.h>

typedef struct
{
  char c1;
  int nx;
  char c2;
} test;

int main(int argc, char const *argv[])
{
  test t = {};
  printf("the actual size of test struct %u\n", (unsigned)sizeof(test));                                  // 12
  printf("the expected size of test struct %lu\n", (unsigned)sizeof(t.c1) + sizeof(t.nx) + sizeof(t.c2)); // 6
  printf("the expected size of test struct %lu\n", (unsigned)sizeof(char) + sizeof(int) + sizeof(char));  // 6

  printf("the offset of t.c1 %u\n", (unsigned)offsetof(test, c1)); // 0
  printf("the offset of t.nx %u\n", (unsigned)offsetof(test, nx)); // 4
  printf("the offset of t.c2 %u\n", (unsigned)offsetof(test, c2)); // 8

  /*
    構造体の比較では == != を使うことはできない（境界調整があるのでビット数が同じとは限らない） 
  */

  return 0;
}
