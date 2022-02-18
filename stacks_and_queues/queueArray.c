#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

int front = -1;
int rear = -1;
int sizeQ = 0;

bool isEmpty()
{
	if (front == -1 && rear == -1) // Can also use size == 0
		return true;
	else
		return false;
}

void enqueue(int *arr, int element)
{
	if(front == (rear+1)%SIZE)
		printf("Queue is full!\n");
	else if(isEmpty())
	{
		front++;
		rear++;
		arr[rear]=element;
		sizeQ++;
	}
	else
	{
		rear = (rear+1)%SIZE;
		arr[rear] = element;
		sizeQ++;
	}
}

void dequeue()
{
	if(isEmpty())
		printf("Queue is empty!\n");
	else if(front == rear) //There is only 1 element
	{
		front--;
		rear--;
		sizeQ--;
	}
	else
	{
		front = (front + 1)%SIZE;
		sizeQ--;
	}
}