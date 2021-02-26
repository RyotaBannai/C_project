#include <stdio.h>

#define NAME_LEN 64

typedef struct student
{
  char name[NAME_LEN];
  int height;
  float weight;
  long scholarship;
} Student;

void coverter(Student *stud)
{
  if (stud->height < 180)
    stud->height = 180;
  if (stud->weight > 80)
    stud->height = 80;
}

int main(void)
{
  Student stud = {"Mike", 175, 62.5, 70000};
  coverter(&stud);
  printf("%s\n", stud.name);
  printf("%d\n", stud.height);
  printf("%.1f\n", stud.weight);
  printf("%ld\n", stud.scholarship);
}