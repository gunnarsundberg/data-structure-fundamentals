#include <stdio.h>
#include <stdlib.h>

struct minHeap
{
    int *arr;
    int heapSize;
    int numElements;
};

struct minHeap insertHeap(struct minHeap heap, int data)
{
    if(heap.numElements == heap.heapSize)
    {
        printf("The heap is full!");
        return heap;
    }
    else
    {
        int index = heap.numElements; // equal to the first empty element
        heap.arr[index] data;
        int parentIndex = (index - 1)/2;
        heap.numElements++;

        while(index != 0 && heap.arr[parentIndex] > heap.arr[index]) //
        {
            int temp = heap.arr[parentIndex];
            heap.arr[parentIndex] = heap.arr[index];
            heap.arr[index] = temp;
            index = parentIndex;
            parentIndex = (index-1)/2;
        }
        return heap;
    }
    
}

struct minHeap deleteHeap(struct minHeap heap)
{
    if(heap.numElements == 0)
    {
        printf("There is no element in the minimum heap!");
        return heap;
    }
    else if(heap.numElements == 1)
    {
        heap.numElements--;
        return heap;
    }
    else
    {
        heap.arr[0] = heap.arr[heap.numElements-1];
        int index = 0;
        heap.numElements--;

        int leftChildIndex = (index*2) + 1;
        int rightChildIndex = (index*2) + 2;

        while(leftChildIndex < heap.numElements)
        {
            if(rightChildIndex == heap.numElements)
            {
                if(heap.arr[index] > heap.arr[leftChildIndex])
                {
                    int temp = heap.arr[leftChildIndex];
                    heap.arr[leftChildIndex] = heap.arr[index];
                    heap.arr[index] = temp;
                }
                break;
            }
            else
            {
                int tempIndex;
                if(heap.arr[leftChildIndex] < heap.arr[rightChildIndex])
                {
                    tempIndex = leftChildIndex;
                }  
                else
                {
                    tempIndex = rightChildIndex;
                }
                int temp = heap.arr[tempIndex];
                heap.arr[tempIndex] = heap.arr[index];
                heap.arr[index] = temp;

                index = tempIndex;
                leftChildIndex = (index*2)+1;
                rightChildIndex = (index*2)+2;
            }
            
        }
    }
    
}