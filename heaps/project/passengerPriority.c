#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Customer struct definition
struct customer
{
    int priority;
    char name[20];
};

/*
*  maxHeap.c by Dr. Karaman
*  Modified for project
*  Heap now stores customer structs instead of ints
*/

struct maxHeap
{
    struct customer *arr;
    int curNumEle;
    int heapSize;
};

void swap(struct customer *arr, int i, int j)
{
    struct customer temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(struct maxHeap heap, int curIndex)
{
    int largest = curIndex; // Initialize largest as root
    int left = 2*curIndex + 1;
    int right = 2*curIndex + 2;

    // If left child is larger than root
    if (left < heap.curNumEle && heap.arr[left].priority > heap.arr[largest].priority)
        largest = left;

    // If right child is larger than largest
    if (right < heap.curNumEle && heap.arr[right].priority > heap.arr[largest].priority)
        largest = right;

    // If largest is not root
    if (largest != curIndex)
    {
        swap(heap.arr, curIndex, largest);

        // Recursively heapify same data
        heapify(heap, largest);
    }
}

struct maxHeap insertHeap(struct maxHeap heap, struct customer newCustomer)
{
    if(heap.heapSize == heap.curNumEle)
    {
        printf("The heap is full!");
        return heap;
    }
    else
    {
        heap.arr[heap.curNumEle] = newCustomer;
        heap.curNumEle++;

        for(int i = heap.curNumEle/2-1; i>=0; i--)
            heapify(heap, i);

        return heap;
    }
}

// NOTE: Decrementing heap.curNumEle wasn't working, so it is decremented from printSorted()
struct maxHeap deleteHeap(struct maxHeap heap)
{
    if(heap.curNumEle == 0)
    {
        printf("There is no element in the minimum heap");
        return heap;
    }
    else if(heap.curNumEle == 1)
    {
        heap.curNumEle = 0;
        return heap;
    }
    else
    {
        heap.arr[0] = heap.arr[heap.curNumEle - 1];
        //heap.curNumEle--; See function comment

        heapify(heap, 0);

        return heap;
    }
};

/*
*  Project 2 - Data Structures - Florida Polytechnic University
*  Gunnar Sundberg - ID: 3513
*/

// Helper function that calculates a customer's priority value
int getPriority(int mileage, int years, int sequence)
{
    return mileage/1000 + years - sequence;
}

// Helper function that takes in a customer's information and returns a customer struct
struct customer createCustomer(char name[], int mileage, int years, int sequence)
{
    struct customer newCustomer;
    strcpy(newCustomer.name, name);
    newCustomer.priority = getPriority(mileage, years, sequence);
    return newCustomer;
}

// Function to read custumers from file and insert them into heap. Returns heap.
struct maxHeap getCustomers(struct maxHeap heap)
{
    FILE *fp;
    char name[20];
    int mileage, years, sequence;
 
    fp = fopen("customers.txt", "r");
 
    if(fp == NULL)
    {
        printf("Error opening file. Make sure customers.txt is in your current working directory and try again.\n");
        exit(1);
    }
    
    // Skips first line
    char buffer[100];
    fgets(buffer, 100, fp);
    
    // For each line until end of file, get customer info and create a customer struct, then add to heap.
    while(fscanf(fp,"%20[^\t]\t%d\t%d\t%d\n", name, &mileage, &years, &sequence) != EOF){
        struct customer newCustomer = createCustomer(name, mileage, years, sequence);
        heap = insertHeap(heap, newCustomer);
    }
    return heap;
}

// Helper function to format output
void printCustomer(struct customer customer)
{        
    printf("\nName: %s -> Priority: %d", customer.name, customer.priority);    
}

// Creates a copy of the heap, then prints root and calls delete until entire heap has printed.
void printSorted(struct maxHeap heap){    
    struct maxHeap temp = heap;
      
    for(int i=0; i<temp.heapSize; i++){        
        printCustomer(temp.arr[0]);
        deleteHeap(temp);
        temp.curNumEle--; // See deleteHeap() function comments
    }
    printf("\n");
}

int main()
{
    struct maxHeap heap;
    heap.heapSize = 15;
    heap.arr = (struct customer *)malloc(sizeof(struct customer)*(heap.heapSize));
    heap.curNumEle = 0;
    heap = getCustomers(heap);
    printSorted(heap);
    
    return 0;
}