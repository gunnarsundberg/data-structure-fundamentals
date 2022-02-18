#include <stdio.h>
#include <stdlib.h>

struct node
{
	int element;
	struct node *next;
	struct node *prev;
};

// Returns element at given position. Must be able to use head or tail.
int get(struct node *pointer, int position)
{
	struct node *temp;
	temp = pointer;

	if(pointer == NULL) 
	{  //List is empty
		printf("List is empty!\n");
		return -1000;
	} 

	else if(pointer->prev == NULL)
	{
		// Pointer is head
		for(int i=0; i < position; i++)
			temp = temp->next;            
		
		return temp->element;
	}
	
	else if(pointer->next == NULL)
	{
		// Pointer is tail
		for(int i=0; i < position; i++)
			temp = temp->prev;            
		
		return temp->element;
	}
	else
	{
		printf("Error: Must pass head or tail.\n");
		return -1000;
	}
}

//Must be able to print from head or tail
void printList(struct node *pointer)
{
	struct node *temp;
	temp = pointer;

	if(pointer == NULL) {
		printf("List is empty!\n");
	}
	else
	if(pointer->prev == NULL)
	{
		printf("List: ");

		while(temp != NULL) {
			printf("%d ", temp->element);
			temp = temp->next;
		}
		printf("\n");
	}
	else
	if(pointer->next == NULL)
	{
		printf("List: ");

		while(temp != NULL) {
			printf("%d ", temp->element);
			temp = temp->prev;
		}
		printf("\n");
	}
}

//Removes element at given position and returns head
struct node *removeEle(struct node *head, int position) {
    struct node *temp, *prev, *next;
    temp = head;
    prev = NULL;
    next = NULL;

    if(head == NULL) {
        printf("List is empty!");
    } else {
        for (int i=0; i< position; i++) {
             temp = temp->next;
        }
        prev = temp->prev;
        if(temp != NULL)
        	next = temp->next;
        prev->next = temp->next;
        next->prev = temp->prev;
        free(temp);
    }

    return head;
}

//Inserts element at the end of the list and returns tail
struct node *insertLast(struct node *tail, int newElement)
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	if(tail == NULL)
	{
	//The element of newNode is assigned
	newNode->element = newElement;
	
	//The next and prev pointer of newNode is assigned
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
	} 
	else
	{
	//The element of newNode is assigned
	newNode->element = newElement;
	
	//The next and prev pointer of newNode is assigned
	newNode->next = NULL;
	newNode->prev = tail;

	//Old tail points to new tail
	tail->next = newNode;

	return newNode;
	}
}

// Returns size. Check if head or tail
int sizeList(struct node *pointer)
{
	struct node *temp;
    temp = pointer;

    int sizeL = 1;

    // if list is empty
    if(pointer == NULL) {
        return 0;
    } 
    else if(pointer->prev == NULL) // head
    {
        while(temp->next != NULL) {
            temp = temp->next;
            sizeL++;
        }

        return sizeL;
    }
    else if(pointer->next == NULL) // tail
    {
        while(temp->prev != NULL) {
            temp = temp->prev;
            sizeL++;
        }

        return sizeL;
    }
    else
    {
    	printf("Error: Must pass head or tail.\n");
		return -1000;
    }
}

//Reverses list and returns new head
struct node *reverseList(struct node *head)
{
	if(head->next != NULL)
	{
		struct node *newNext, *newPrev;
		newNext = head->prev;
		newPrev = head->next;
		head->prev=newPrev;
		head->next=newNext;
		return reverseList(head->prev);
	}
	else //base case: tail will be reversed and returned as new head
	{
		head->next=head->prev;
		head->prev=NULL;
		return head;
	}
}

int main()
{

	struct node *head = NULL;
	struct node *tail = NULL;

	printf("Add 1, 2, 3, 7, 9 to list, then print:\n");
	head = insertLast(head, 1);
	tail = head;
	tail = insertLast(tail, 2);
	tail = insertLast(tail, 3);
	tail = insertLast(tail, 7);
	tail = insertLast(tail, 9);
	printList(head);
	printf("\n");

	printf("Size of list: %d\n", sizeList(head));
	printf("\n");

	printf("Remove 2nd element:\n");
	head = removeEle(head, 1);
	printList(head);
	printf("\n");

	printf("New size of list: %d\n", sizeList(head));
	printf("\n");

	printf("Add 4 and 5 to list:\n");
	tail = insertLast(tail, 4);
	tail = insertLast(tail, 5);
	printList(head);
	printf("\n");

	printf("New size of list: %d\n", sizeList(head));
	printf("\n");

	printf("Element at position 3: %d\n", get(head,2));
	printf("\n");

	printf("Print from tail:\n");
	printList(tail);
	printf("\n");

	printf("Print from head:\n");
	printList(head);
	printf("\n");

	printf("Reverse list: \n");
	tail = head;  // reverseList() only returns head, so we need to set tail
	head = reverseList(head);
	printList(head);
	
}