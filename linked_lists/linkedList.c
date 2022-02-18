#include <stdio.h>
#include <stdlib.h>

int size = 0;

struct node 
{
	int element;
	struct node *next;
};

struct node *insertLast(struct node *head, int newElement)
{
	struct node *newNode, *temp;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->element = newElement;
	newNode->next = NULL;

	temp = head;

	if(head == NULL)
		head = newNode;
	else{
		

		while(temp->next != NULL)
			temp = temp->next;

		temp->next = newNode;
	}

	size++;
	return head;
}

int get(struct node *head, int position)
{
	if(position >= size)
		return 0;
	
	struct node *temp;
	temp = head;

	if(head == NULL){
		printf("List is empty\n");
		return 0;
	}
	else{
		for(int i=0; i<position; i++)
		{
			temp = temp->next;
		}

		return temp->element;
	}

}

void printList(struct node *head)
{
	if(head == NULL)
		printf("List is empty.");
	else {
	
	struct node *temp;
	temp = head;

	printf("List: ");
	
	while(temp->next != NULL){

		printf("%d ", temp->element);
		temp = temp->next;
	}

	printf("%d \n", temp->element);

	}

}

struct node *removeElement(struct node *head, int position)
{
	struct node *prev, *temp;
	temp = head;
	prev = NULL;

	if(head == NULL)
	{
		printf("The list is empty\n");
		return NULL;
	}
	else
	{
		for(int i = 0; i < position-1; i++)
		{
			prev = temp;
			temp = temp->next;
		}

		prev->next = temp->next;
		free(temp);
	}
}

int sizeList(struct node *head)
{
	int size = 0;
	struct node *temp;
	temp = head;

	if(head==NULL)
		return size;
	else
	{
		while(temp->next != NULL){
			size++;
			temp=temp->next;
		}
		size++;
		return size;
	}
}

struct node *reverseIterative(struct node *head)
{
	struct node *temp, *next, *prev;
	temp = head;
	prev = NULL;

	while(temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		temp - next;
	}

	head = prev;
	return head;
}

int main(){

	struct node *head = NULL;

	head = insertLast(head, 3);
	head = insertLast(head, 12);
	head = insertLast(head, 4);
	head = insertLast(head, 56);
	head = insertLast(head, 9);
	head = insertLast(head, 7);

	printList(head);
	printf("Size of list: %d\n", sizeList(head));

	head = removeElement(head, 2);

	printList(head);
	printf("Size of list: %d\n", sizeList(head));


}