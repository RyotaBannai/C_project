#include <stdio.h>
enum
{
  BLACK,
  BLUE,
  RED,
  GREEN,
  MAGENTA,
  CYAN,
  YELLOW,
  WHITE,
  GRAY,
  BRIGHT_BLUE,
  BRIGHT_RED,
  BRIGHT_GREEN,
  BRIGHT_MAGENTA,
  BRIGHT_CYAN,
  BRIGHT_YELLOW,
  BRIGHT_WHITE
};

void cls(void)
{
  printf("\x1B[2j");
}

void locate(int x, int y)
{
  printf("\x1B[%d;%dH", y, x);
}

void colorx(int fg, int bg)
{
  int col[] = {30, 34, 31, 32, 35, 36, 33, 37};
  printf("\x1B[0;");
  if (fg > WHITE)
    printf("1;");
  printf("%d;%dm", col[fg % 8], col[bg % 8] + 10);
}

void color(int col)
{
  colorx(col, BLACK);
}

int main(void)
{
  cls();
  locate(3, 2);
  color(WHITE);
  printf("kanji");

  locate(3, 4);
  color(BLUE);
  printf("japanese");

  locate(3, 6);
  colorx(BLACK, BLUE);
  printf("ABCDE");

  locate(3, 8);
  colorx(BLUE, WHITE);
  printf("Hello World!\n");

  color(WHITE);

  return 0;
}