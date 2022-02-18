#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[j];
    arr[j]=arr[i];
    arr[i]=temp;
}

void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void heapify(int *arr, int heapSize, int curIndex)
{
    int largest = curIndex;
    int left = (2*curIndex)+1;
    int right = (2*curIndex)+2;

    if(left < heapSize && arr[left] > arr[largest])
        largest = left;
    if(right < heapSize && arr[right] > arr[largest])
        largest = right;
    if(largest != curIndex)
    {
        swap(arr, curIndex, largest);
        heapify(arr, heapSize, largest);
    }
}

void heapSort(int *arr, int heapSize)
{
    for(int i = heapSize/2 - 1; i >=0; i--)
    {
        heapify(arr, heapSize, i);
    }
    for(int i = heapSize-1; i>=0; i--)
    {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}