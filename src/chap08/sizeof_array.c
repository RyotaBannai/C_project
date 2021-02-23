/* header files */
#include <stdio.h>
#include <stdlib.h>
/* macros */

/* function prototype/ function interface (function's name and type signature, but omits the function body) */
void printSizeOf(int *intArray);
void printLength(int *intArray);

int main(int argc, char const *argv[])
{
  int array[] = {1,
                 2,
                 3,
                 4,
                 5};
  printf("sizeof of 'array': %d\n", (int)sizeof(array));
  printSizeOf(array);
  printf("length of 'array': %d\n", (int)(sizeof(array) / sizeof(array[0])));
  printLength(array);
  /*
    sizeof of 'array': 20
    sizeof of 'parameters': 4
    length of 'array': 5
    length of 'parameters': 1
  */
}

/* The array decays to a pointer when passed. */
/* int *' instead of 'int [] */
void printSizeOf(int *intArray)
{
  printf("sizeof of 'parameters': %d\n", (int)sizeof(*intArray));
}

void printLength(int *intArray)
{
  printf("length of 'parameters': %d\n", (int)(sizeof(*intArray) / sizeof(intArray[0])));
}