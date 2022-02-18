/*
*  Gunnar Sundberg - Data Structures Fall 2019 - Florida Polytechnic University
*  Project 1: Stack-based implementation of Reverse Polish Calculator
*  Skip to Section 2 for code unique to this project. 
*/

/*
*  Section 1: Linked List Implementation
*/

//Bayazit Karaman
//Data Structures
//Florida Polytechnic University

//A Linked List Based Stack Implementation

//Modified slightly by Gunnar Sundberg for Project-1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int element;
    struct node *next;
};

struct node *top = NULL;

void push(int ele)
{
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));

    newNode->element = ele;
    newNode->next = top;
    top = newNode;
}

// Pop changed to return data from popped node when called
int pop()
{
    struct node *temp;
    temp = top;

    if(top == NULL)
    {
        printf("Stack is empty!!!\n");
        return 0;
    }
    else
    {
        top = top->next;
        int popData = temp->element;
        free(temp);
        return popData;
    }
}

bool isEmpty()
{
    if(top == NULL)
        return true;
    else
        return false;
}

int returnTopElement()
{
    return top->element;
}

void printStack()
{
    struct node *temp;
    temp = top;

    printf("Stack : ");

    while(temp != NULL){
        printf("%d ", temp->element);
        temp = temp->next;
    }
    printf("\n");
}

/*
*  Section 2: Project-1 Functions
*/

/*
*  isOperator - helper function - array input and one by one
*  Takes in character c and determines if c is an operator as defined by the assignment.
*/
bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else
        return false;
}

/*
*  compute - helper function - array input and one by one
*  Takes in operator and uses it to determine what computation should be performed, then performs it.
*  User specifies if operation should be printed through parameter printOperation
*/
void compute(char operator, bool printOperation)
{
    int pop1 = pop();
    int pop2 = pop();
    
    switch(operator)
    {
        case '+': 
            push(pop1+pop2);
            break;
        case '-': 
            push(pop1-pop2);
            break;
        case '*': 
            push(pop1*pop2);
            break;
        case '/': 
            push(pop1/pop2);
            break;
    }
    if(printOperation)
        printf("\n%d %c %d = %d",pop1,operator,pop2,returnTopElement());
}

/*
*  readData - helper function - one by one input
*  Reads input from the user and determines if it is operator by calling isOperator.
*  If not an operator, push to stack. User enters q to quit.
*  Note: Only works up to 2 digits.
*/
void readData()
{
    int stackSize = 0;
    bool runCondition = true;
    while(runCondition == true)
    {
        char input[3];
        printf("\nInput: ");
        scanf(" %s", input);
        if(input[0] == 'q')
            break;
        else if(isOperator(input[0]) && stackSize < 2)
            printf("\nNot enough numbers to perform operation. Enter a number.\n");
        else if(isOperator(input[0]) && stackSize > 1)
            compute(input[0], true);
        else
        {
            push(atoi(input));
            stackSize++;
        }
    }  
}

/*
*  oneByOne function
*  Reads numbers and operators from user and performs operations as specified by the reverse polish method.
*/
int oneByOne()
{
    printf("\n*** One by one input ***");
    printf("\nReading input. Enter q to quit.");
    readData();
    return pop();
}

/*
*  arrayInput function
*  Reads numbers and operators from an array and performs operations as specified by reverse polish notation
*  Note: Only accepts 2 digit numbers and the number of columns of input array must be three
*  Note: The number of rows in the 2D array must be passed into parameter numRows
*/ 
int arrayInput(char inputArray[][3], int numRows)
{ 
    int i = 0;

    printf("Input: [");

    while(i < numRows)
    {
        if (isOperator(inputArray[i][0]))
        {
            printf(" %c ", inputArray[i][0]);
            compute(inputArray[i][0], false);
        }
        else
        {
            printf(" %d ", atoi(inputArray[i]));
            push(atoi(inputArray[i]));
        }
        i++;
    }
    
    printf("] ");
    
    return pop();
}

/*
*  Test cases
*  Note: Test arrays must have 3 columns and at most 2 digit input.
*/
int main(){
    printf("\nResult: %d\n", oneByOne());
    
    printf("\n*** Array Input ***\n");

    char test1[5][3] = {{'5',}, {'3'}, {'4'}, {'+'}, {'*'}};
    printf("\nResult: %d\n", arrayInput(test1, 5));

    char test2[3][3] = {{'5'}, {'8'}, {'+'}};
    printf("\nResult: %d\n ", arrayInput(test2, 3));
}