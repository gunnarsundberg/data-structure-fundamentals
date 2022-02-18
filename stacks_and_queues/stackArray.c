#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000

int top = -1;

void push(int element, int *arr)
{
	if(top == SIZE - 1)
	{
		printf("Stack Overflow!\n");
		return;
	}
	else
	{
		top++;
		arr[top] = element;
	}
}

int pop(int *arr)
{
	if(top == -1)
	{
		printf("Stack is empty!\n");
		return -1;
	}
	else
	{
		top--;
		return arr[top+1];
	}
}

int topElement(int *arr)
{
	if(top == -1)
		return -1;
	else
		return arr[top];
}

bool isEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}

void printStack(int *arr)
{
	printf("Stack:\n");
	for(int i = 0; i <=top; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int size()
{
	return top+1;
}

int main()
{
	int arr[SIZE];

	bool result;
	result = isEmpty();

	if(result == true)
		printf("Your stack is empty\n");
	else
		printf("Your stack is not empty\n");

	push(5, arr);
	push(6, arr);
	push(7, arr);
	push(8, arr);
	push(9, arr);

	printStack(arr);

	pop(arr);
	printStack(arr);

	pop(arr);
	printStack(arr);

	printf("The top element of the stack is %d\n", topElement(arr));

	return 0;
}