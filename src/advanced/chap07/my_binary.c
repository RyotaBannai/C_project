#include <stdio.h>
/*
  check $od -An -vtx1 TEST_BIN
  ->            65  01  00  00
  357(in 10) -> 165(in 16) , little endian だと言うことがわかる. 実際 intel の cpu を積んだ pc は little endian.

  http://cms.phys.s.u-tokyo.ac.jp/~naoki/CIPINTRO/NETWORK/endian.html
*/
int main(int argc, char const *argv[])
{
  FILE *fp;
  int no = 357;
  fp = fopen("TEST_BIN", "wb");
  if (fp != NULL)
  {
    fwrite(&no, sizeof(int), 1, fp);
    fclose(fp);
  }
  return 0;
}
