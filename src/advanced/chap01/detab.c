/*
  ファイルのタブを半角スペースに置き換える
  タブはデフォルトで 4 つの半角スペースに置き換えるが、引数 -t で変更可能
  $ ./a.out -t4 sample.c

  * vscode など保存時に自動フォーマットする機能がある場合, \t は自動で半角スペースに置き換わる '	' -> '..'
  * to stop this, cmd+, and search for 'format' and uncheck 'Format on save' option.
  * to show invisible characters edit settings.json and add `"editor.renderWhitespace": "all"` option
*/
#include <stdio.h>
#include <stdlib.h>

void detab(FILE *in, FILE *out, int tab_width)
{
  int ch;
  int pos = 1;
  int num;
  while ((ch = fgetc(in)) != EOF)
  {
    switch (ch)
    {
    case '\t':
      // printf("this is tab");
      num = tab_width - (pos - 1) % tab_width; // タブの前に 半角スペースなどが入っている場合、pos = 1 になるので、それも含めて tab_width 分スペースを追加
      for (; num > 0; num--)
      {
        fputc('.', out);
        pos++;
      }
      break;
    case '\n':
      fputc(ch, out);
      pos = 1;
      break;
    default:
      fputc(ch, out);
      pos++;
      break;
    }
  }
}

int main(int argc, char *argv[])
{
  int tab_width = 4;
  FILE *fp;
  // argc(argument count) コマンドライン引数数
  printf("the number of args %d\n", argc);
  // argv(argument vector) には、ダブルポインタが入る（文字配列の配列）*argv[] == **argv (ポインタの配列)
  // 第三引数で環境変数を渡すこともできる(int argc, char **argv, char** envp)
  if (argc < 2)
  {
    detab(stdin, stdout, tab_width);
  }
  else
  {
    while (--argc > 0)
    {
      // printf("%s\n", *(++argv)); // 引数一つ分取得
      if (**(++argv) == '-')
      {
        if (*++(*argv) == 't')
        {
          tab_width = atoi(++*argv); // int atoi(const char *str)
        }
        else
        {
          printf("parameter %c is invalid \n", **argv);
        }
      }
      // do NOT pass filename starts with '-'
      else
      {
        if ((fp = fopen(*argv, "r")) == NULL)
        {
          printf("couldn't open file %s \n", *argv);
        }
        else
        {
          detab(fp, stdout, tab_width);
          fclose(fp);
        }
      }
    }
  }

  return 0;
}
