#include <stdio.h>

struct rec
{
  char a[9];
  char b[7];
  char c[9];
  char d[10];
  char e[8];
};

int fgetword(FILE *fp, char *str)
{
  int ch;
  while ((ch = fgetc(fp)) != EOF && ch != '\t' && ch != '\n')
  {
    if (ch != ' ')
      *str++ = ch; // 追加してアドレスをひとつ先に進める
  }
  *str = '\0'; // 連続でタブが入っている（欠損値）の場合は、while からすぐ break するため null 文字を入れる.
  return ch;
}

int getrec(FILE *fp, struct rec *dat)
{
  printf("called\n");
  if (fgetword(fp, dat->a) == EOF)
    return EOF;
  if (fgetword(fp, dat->b) == EOF)
    return EOF;
  if (fgetword(fp, dat->c) == EOF)
    return EOF;
  if (fgetword(fp, dat->d) == EOF)
    return EOF;
  if (fgetword(fp, dat->e) == EOF)
    return EOF;

  return 0;
}

int main(void)
{
  FILE *fp;
  struct rec dat;

  fp = fopen("data2.txt", "r");
  //  while の中身が EOF になるときに break するため, データの最後の行は改行が必要
  while (getrec(fp, &dat) == 0)
  {
    printf("%s\t%s\t%s\t%s\t%s\n", dat.a, dat.b, dat.c, dat.d, dat.e);
  }
  fclose(fp);
  return 0;
}
