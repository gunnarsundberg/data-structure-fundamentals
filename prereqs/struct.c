#include <stdio.h>
#include <stdlib.h>

struct Student
{
  char firstname[40];
  char lastname[40];
  int id;
};

int main()
{
  struct Student stu1 = {"Bayazit","Karaman",19};
  
  struct Student stu2 = {"John","Snow",28};

  // Print structure members
  printf("First name of student 1 is %s", stu1.firstname);
  printf("\nLast name of student 2 is %s", stu2.lastname);
  
  struct Student *pointerStu1 = &stu1;
  struct Student *pointerStu2 = &stu2;

  // Print structure members using pointer to struct
  printf("\nFirst name of student 1 is %s",pointerStu1->firstname);
  printf("\nLast name of student 2 is %s",pointerStu2->lastname);

  return 0;
}
