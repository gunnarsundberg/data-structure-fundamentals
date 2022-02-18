#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int element;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
int size = 0;

bool isEmpty()
{
	if(front == NULL && rear == NULL) //if front is null it's empty. Just for illustration
		return true;
	else
		return false;
}

void enqueue(int newElement)
{
	struct node *newNode;

	newNode = (struct node*) malloc(sizeof(node));
	newNode->element = newElement;
	newNode->next = NULL;
	
	if(isEmpty())
	{
		front = newNode;
		rear = newNode;
		size++;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
		size++;
	}
}

void dequeue()
{
	if(isEmpty())
		printf("Queue is empty. Cannot dequeue!\n");
	else if(size == 1)
	{
		front = NULL;
		rear = NULL;
		size--;
	}
	else
	{
		struct node *temp = front;

		front = front->next;
		free(temp);
	}
}

