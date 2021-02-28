#include <time.h>
#include <stdio.h>

void basic_io_file()
{
  FILE *fp; // streamFp
  char *file_name = "abc";
  fp = fopen(file_name, "r");
  if (fp == NULL) // returns NULL pointer when it fails to read file.
  {
    printf("couldn't open file %s\n", file_name);
  }
  else
  {
    printf("opened file %s and closing...\n", file_name);
    fclose(fp);
  }
}
void history_of_call()
{
  FILE *fp;
  char *file_name = "dt_dat";
  if ((fp = fopen(file_name, "a")) == NULL) // w/a mode creates new file if it doesn't exist.
  {
    printf("couldn't open file %s\n", file_name);
  }
  else
  {
    time_t now = time(NULL);
    struct tm *timer = localtime(&now);
    fprintf(fp, "%d %d %d %d %d %d\n",
            timer->tm_year + 1900,
            timer->tm_mon + 1,
            timer->tm_mday,
            timer->tm_hour,
            timer->tm_min,
            timer->tm_sec);
    fclose(fp);
  }
}

void read_from_file()
{
  // https://stackoverflow.com/questions/40205850/fscanf-segmentation-fault-11
  history_of_call();

  FILE *fp;
  char *file_name = "hw.dat"; // hw height weight
  if ((fp = fopen(file_name, "r")) == NULL)
  {
    printf("couldn't open file %s\n", file_name);
  }
  else
  {
    printf("opened file %s\n", file_name);
    int number_of_studs = 0;
    double h, w; // long float
    double sum_h = 0.0;
    double sum_w = 0.0;
    char name[100];                                   // do not use char *name
    while (fscanf(fp, "%s%lf%lf", name, &h, &w) == 3) // スペースを入れなくても良い
    {
      number_of_studs++;
      sum_h += h;
      sum_w += w;
      printf("%-10s %5.1f %5.1f\n", name, h, w);
    }
    printf("----------------------\n");
    printf("%-10s %5.1f %5.1f\n", "average", sum_h / number_of_studs, sum_w / number_of_studs);
    fclose(fp);
  }
}

void rw_binary()
{
  /*
    テキストファイル：文字列が'数値の桁数に依存'する (345 -> 3 bytes, 3456 -> 4 bytes. 345 は '3', '4', '5' の文字（テキスト）として出力されるので、'3' = 1 char = 1 byte となる)
    バイナリファイル：文字列（バイト数）が'数値の桁数に依存'しない (345, 3456 いずれも sizeof(int) で一定. int は基本的に 2 bytes)
  */
  FILE *fp;
  char *file_name = "pi";
  if ((fp = fopen(file_name, "wb")) == NULL)
  {
    printf("couldn't open file %s\n", file_name);
  }
  else
  {
    double pi = 3.14159265358979323846;
    printf("%-15s%23.21f\n", "pi is ", pi);
    fwrite(&pi, sizeof(double), 1, fp);
    fclose(fp);
  }
  // check if data doesn't decay.
  if ((fp = fopen(file_name, "rb")) == NULL)
  {
    printf("couldn't open file %s\n", file_name);
  }
  else
  {
    double read_pi;
    fread(&read_pi, sizeof(double), 1, fp);
    printf("%-15s%23.21f\n", "read pi is ", read_pi);
    fclose(fp);
  }
}

void test()
{
  char test[100];
  scanf("%s", test); // 改行文字を空読みしなくても除去される.
  printf("%s", test);
}

int main(int argc, char const *argv[])
{
  // read_from_file();
  // rw_binary();
  return 0;
}
