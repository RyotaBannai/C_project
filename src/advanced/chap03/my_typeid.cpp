#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
  char c;
  short h;
  int i;
  long l;

  cout << "type of c: " << typeid(c).name() << endl;                       // c
  cout << "type of h: " << typeid(h).name() << endl;                       // h
  cout << "type of i: " << typeid(i).name() << endl;                       // i
  cout << "type of l: " << typeid(l).name() << endl;                       // l
  cout << "type of 'A': " << typeid('A').name() << endl;                   // c
  cout << "type of \"ABC\": " << typeid("ABC").name() << endl;             // A4_c
  cout << "type of const char *: " << typeid(const char *).name() << endl; // PKc
  cout << "type of char *: " << typeid(char *).name() << endl;             // Pc
  cout << "type of 100: " << typeid(100).name() << endl;                   // i
  cout << "type of 100U: " << typeid(100U).name() << endl;                 // j
  cout << "type of 100L: " << typeid(100L).name() << endl;                 // l
  cout << "type of 100UL: " << typeid(100UL).name() << endl;               // m
}