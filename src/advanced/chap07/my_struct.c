/*
  c 言語では、データの構造が実質的に同じであれば、同一の型であるとみなされる'構造等価性' ではなく、
  型に与えられた名前が同じでなければ、同一の型としてみなされないという'名称等価性'が採用されている
  → そのため、タグ名が省略された構造体（struct）を２つ宣言すると、それぞれは別の型として認識される（typedef などを使って回避する）
*/

typedef struct
{
  double re, im;
} complex;

typedef complex *complex_ptr; // 構造体のポイント型も typedef で宣言可

int main(int argc, char const *argv[])
{
  complex a, b = {0.0};
  complex x, y = {0.0};
  complex *pa, *pb;
  complex_ptr pc, pd;

  a = b;
  x = b;
  pa = &a;
  pb = &b;
  pc = pa;
  pd = pc;
  return 0;
}
