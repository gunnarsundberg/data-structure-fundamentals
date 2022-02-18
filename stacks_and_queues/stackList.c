#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
	int element;
	struct node *next;
};

struct node *top = NULL;

bool isEmpty()
{
	if(top == NULL)
		return true;
	else
		return false;
}

void *push(int newElement)
{
	struct node *newNode, *temp;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->element = newElement;
	newNode->next = top;
	top = newNode;

}

int pop()
{
	if (isEmpty()){
		printf("Stack is empty!");
		return -1;
	}
	else
	{
		struct node *temp = top;
		top = temp->next;
		int pop = temp->element;
		free(temp);
		return pop;
	}
}

void printStack()
{
	if(isEmpty())
		printf("Stack is empty.");
	else {
	
	struct node *temp;
	temp = top;

	printf("Stack:\n");
	
	while(temp->next != NULL){

		printf("%d ", temp->element);
		temp = temp->next;
	}

	printf("%d \n", temp->element);
}
}

int main()
{
	bool result;
	result = isEmpty();

	if(result == true)
		printf("Your stack is empty\n");
	else
		printf("Your stack is not empty\n");

	push(5);
	push(6);
	push(7);
	push(8);
	push(9);

	printStack();

	printf("Pop: %d\n",pop());
	printf("Pop: %d\n",pop());

	printStack();


}