#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int size)
{
	int minIndex, temp;

	for(int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for(int j = i+1; j < size; j++)
		{
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}

		if(minIndex !=i)
		{
			temp = arr[i];
			arr[i]=arr[minIndex];
			arr[minIndex]= temp;
		}
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
	selectionSort(arr, sizeOfArray);
	printf("Sorted array: \n");
	printArr(arr, sizeOfArray);

}