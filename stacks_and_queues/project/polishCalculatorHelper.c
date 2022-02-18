//Bayazit Karaman
//Florida Polytechnic University
//COP 4415 - Data Structures

#include <stdio.h>
#include <stdlib.h>

int *tempPointer=NULL;

struct MyList{
    int curPos;
    int *arr;
    int sizeOfArray;
};

struct MyList get(struct MyList curList, int pos)
{
    if(curList.curPos == -1)
    {
        printf("List is empty! Please add some elements!\n");
    }
    else if(pos > curList.curPos)
    {
        printf("There is no data at index %d! Try it later!\n", pos);
    }
    else{
        printf("List[%d] is %d\n", pos, *((curList.arr)+pos));
    }

    return curList;
}

struct MyList expand(struct MyList curList)
{
    curList.sizeOfArray = curList.sizeOfArray * 2;
    tempPointer = (int *)malloc(sizeof(int)* (curList.sizeOfArray));

    for(int i = 0; i < (curList.sizeOfArray/2); i++)
    {
        *(tempPointer+i) = *((curList.arr)+i);
    }

    free(curList.arr);
    curList.arr = tempPointer;
    tempPointer = NULL;

    return curList;
}


void printList(struct MyList curList)
{
    printf("List:  ");

    for(int i=0; i < curList.curPos+1; i++)
    {
        printf("%d  ", *((curList.arr)+i));
    }

    printf("\n");

}

struct MyList insertLast(struct MyList curList, int newElement)
{
    int index = curList.curPos + 1;

    if(curList.sizeOfArray == index)
    {
        curList = expand(curList);
    }

    *((curList.arr)+index) = newElement;
    curList.curPos++;
    printList(curList);
    return curList;
}


struct MyList ask(struct MyList curList)
{
    int selection, position, newEle;

    printf("Hello your list is ready! What would you like to do?\n");

    printf("1. Call get() function \n2. Call insertLast() function \n3."
           " Call insertAt() function \n4. Call insertBeg() function"
           " \n5. Call remove() function \n6. Call replace() function."
           "\n7. Call size() function\nSelection: ");

    scanf("%d", &selection);

    switch(selection){
        case 1 :
            printf("Please enter the index number to access your data: ");
            scanf("%d", &position);
            return get(curList, position);
            break;
        case 2 :
            printf("Please enter the new data to your list: ");
            scanf("%d", &newEle);
            return insertLast(curList, newEle);
            break;
        default :
            printf("Invalid input!\n");
            ask(curList);
    }
}

int main()
{

    struct MyList newList = {-1,NULL,10};
    newList.arr = (int *)malloc(sizeof(int)* (newList.sizeOfArray));

    while(1)
    {
        newList = ask(newList);
    }

    return 0;
}
