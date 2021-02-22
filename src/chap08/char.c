#include <stdio.h>
#include <stdlib.h> // for malloc
#include <math.h>
#include <stdlib.h>
#include "chap08.h"

/*
https://www.fine.cs.kobe-u.ac.jp/members/kamada/old/proron/index.html#headers
*/

void warmups()
{
  char zero = '0';
  char one = '1';
  char chars[] = {zero, one, '\0'};
  char charss[] = "111";

  for (int i = 0; i < sizeof(chars) / sizeof(chars[0]); i++)
  {
    printf("%d\n", chars[i]);
  }
  printf("chars: %s\n", chars);

  // better solusion but you need to know enough size of char*
  int ENOUGH = 32;
  char my_str[ENOUGH];
  sprintf(my_str, "%d", 42);
  printf("%s\n", my_str);

  // get length of array
  // snprintf tells you length if you call it with NULL, 0 as first parameters:
  int length_from_chars = snprintf(NULL, 0, "%s", chars);
  int length_from_charss = snprintf(NULL, 0, "%s", charss);
  printf("%d\n", length_from_chars);  // 2
  printf("%d\n", length_from_charss); // 3

  //
  char str[length_from_charss];
  sprintf(str, "%s", charss);
  printf("%s\n", str);
}

void allocate_character_from_int()
{
  int x = 48; // '0'
  int length = snprintf(NULL, 0, "%d", x);
  char *str = malloc(length + 1);
  sprintf(str, "%d", x);
  printf("%s\n", str);
  free(str);

  // if you are using GCC, you can use the GNU extensino asprintf function
  // this also works!
  char *my_str;
  asprintf(&my_str, "%i", 12341234); // expect char **
  printf("%s\n", my_str);
  free(my_str);
}

void experiments()
{
  /*
    how to determine ENOUGH is really enough? or,
    how to calculate the number of characters?

    // https://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c/23840699
  */
  printf("%lu\n", sizeof(char)); // 1
  printf("%lu\n", sizeof(int));  // 4
  int num = 48;                  // 1
  char ints = 111;               // 2
  unsigned long size_of_ints = sizeof(char) * (int)log10(ints);
  printf("%lu\n", size_of_ints);

  // now use this size...
  char my_str[size_of_ints];   // size が小さいと、Illegal instruction: 4 とかになる (osx)
  sprintf(my_str, "%d", ints); // expect const void *
  printf("%s\n", my_str);
  printf("%s\n", my_str);

  // #define ENOUGH ((CHAR_BIT * sizeof(int) - 1) / 3 + 2) とかでも確保できる
}

void show_char()
{
  int my_int = 111;
  printf("char: %c\n", my_int);

  // int to char
  int i = 8;
  char c = '0' + i;
  printf("%c\n", c); // '8'

  // cast doesn't work!
  int i = 9;
  char c = (char)i;
  printf("%c", c); // '\t' ('9'に変換されるわけではない)

  // https://marycore.jp/prog/c-lang/convert-number-to-char/
}

int main(int argc, char const *argv[])
{
  // warmups();
  show_char();
  // allocate_character_from_int();
  // experiments();
}

// atoi: convert string to int as much as it can
// https://www.educative.io/edpresso/how-to-convert-a-string-to-an-integer-in-c