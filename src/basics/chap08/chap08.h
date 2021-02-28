#ifndef __CHAP08_H__
#define __CHAP08_H__
/* 上の 2 行はおまじない */
/* 
同じ宣言を 2 度以上読み込まないようにするためのもの.
もし、この header file を同じ XXX.c file から 2 度読み込んだ場合でも、 2 度目の読み込みにおいては、
すでに __FILENAME_H__ が define されているので、2 度読み防止できる
*/

void warmups();
void allocate_character_from_int();

/* 最後の行もおまじない */
#endif /* !define(__CHAP08__) */