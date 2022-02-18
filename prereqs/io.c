#include <stdio.h>
int main()
{
  int a, b, c;

  printf("Please enter the first number:");
  scanf("%d", &a);

  printf("\nPlease enter the second number:");
  scanf("%d", &b);

  c = a / b;

  printf("a = %d and b = %d so c = %d \n", a, b, c);
  
  return 0;
}