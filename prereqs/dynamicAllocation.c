#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    printf("Enter the size of array: ");
    scanf("%d", &num);
    /*
    You could specify the length of the array first using:
    int arr[num];
    or you could dynamically allocate the array using the 
    size given by the user multiplied by the size of each
    entry, which is of type int.
    */
    int* arr = (int*) malloc(num * sizeof(int));
    /*
    Antother option is calloc, which initializes all elements
    to 0. For example:
    int* arr = (int*) calloc(num, sizeof(int));
    */
    
    // Initialize the array
    int i=0;
    while(i < num)
    {
        arr[i] = i * i;
        i = i + 1;
    }
    
    // Print each element of the array
    i = 0;
    while(i < num)
    {
        printf("%d is = %d \n", i+1, arr[i]);
        i = i + 1;
    }

    // Reallocate memory pointed to by arr
    // This will double the size of arr
    int *arr2 = realloc(arr, 2 * num * sizeof(int));

    // Print arr2
    i = 0;
    while(i < 2 * num)
    {
        printf("%d is = %d \n", i+1, arr2[i]);
        i = i + 1;
    }

    return 0;
}
