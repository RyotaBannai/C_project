/*Function return size of string and convert signed  *
 *integer to ascii value and store them in array of  *
 *character with NULL at the end of the array        */
#include <stdio.h>

int main(void) {}

int itoa(int value, char *ptr)
{
  int count = 0, temp;
  if (ptr == NULL)
    return 0;
  if (value == 0)
  {
    *ptr = '0';
    return 1;
  }

  // TODO: understand inside if block
  if (value < 0)
  {
    value *= (-1);
    *ptr++ = '-';
    count++;
  }

  // TODO: understand codes below.
  for (temp = value; temp > 0; temp /= 10, ptr++)
    ;
  *ptr = '\0';
  for (temp = value; temp > 0; temp /= 10)
  {
    *--ptr = temp % 10 + '0';
    count++;
  }
  return count;
}