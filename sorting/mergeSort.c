#include <stdlib.h>
#include <stdio.h>

void merge(int *arr, int left, int mid, int right)
{
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	int leftHalf[leftSize], rightHalf[rightSize];

	for(int i=0; i < leftSize; i++)
	{
		leftHalf[i] = arr[left + i];
	}
	
	for(int i = 0; i < rightSize; i++)
	{
		rightHalf[i] = arr[mid + i + 1];
	}

	int i = 0, j = 0, k = left;

	while(i < leftSize && j < rightSize)
	{
		if(leftHalf[i] <= rightHalf[i])
		{
			arr[k] = leftHalf[i];
		}
		else
		{
			arr[k] = rightHalf[j];
			j++;
		}
	}

	

}