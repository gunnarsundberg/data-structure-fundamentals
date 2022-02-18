#include <stdio.h>

int main()
{
	int a;
	int *p;

	// p points to a
	p = &a;

	a = 5;

	// Print value of p (address of a)
	printf("%d\n",p);
	// Print value at the address p points to (5)
	// This is called dereferencing
	printf("%d\n",*p);
	// Print address of p
	// This is where p is stored in memory
	printf("%d\n",&p);

	return 0;
}