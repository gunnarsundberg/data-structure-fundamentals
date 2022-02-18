#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int size)
{
	int currentNumber;
	int currentIndex;

	for(int i = 1; i < size; i++)
	{
		currentIndex = i;
		currentNumber = arr[i];

		while(currentIndex > 0 && arr[currentIndex-1] > currentNumber)
		{
			arr[currentIndex] = arr[currentIndex - 1];
			currentIndex--;
		}

		arr[currentIndex] = currentNumber;
	}
}

void printArr(int *arr, int size)
{
	printf("[");
	for (int i = 0; i < size; i++)
        printf(" %d ", arr[i]);
    printf("]\n");
}

int main()
{
	int arr[] = {1,8,666,43,765,2,47,98};
	int sizeOfArray = sizeof(arr) / sizeof(arr[0]);
	printf("Starting array: \n");
	printArr(arr, sizeOfArray);
	insertionSort(arr, sizeOfArray);
	printf("Sorted array: \n");
	printArr(arr, sizeOfArray);

}