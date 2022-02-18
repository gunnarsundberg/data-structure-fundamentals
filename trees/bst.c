// Gunnar Sundberg
// Florida Polytechnic University
// COP 4415 - Data Structures

#include <stdio.h>
#include <stdlib.h>

struct BTNode
{
    int data;
    struct BTNode *left;
    struct BTNode *right;
};

struct BTNode * insertNode(struct BTNode *root, int newData)
{
    struct BTNode *newNode;
    newNode = (struct BTNode *) malloc(sizeof(struct BTNode));
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
    {
        root = newNode;
    }
    else if(newData > root->data)
    {
        root->right = insertNode(root->right, newData);
    }
    else
    {
        root->left = insertNode(root->left, newData);
    }

    return root;
}

void printPreOrderTree(struct BTNode *root)
{
    if(root == NULL)
        return NULL;

    printf("%d ", root->data);

    printPreOrderTree(root->left);

    printPreOrderTree(root->right);
}

void printInOrderTree(struct BTNode *root)
{
    if(root == NULL)
        return NULL;

    printInOrderTree(root->left);
    printf("%d ", root->data);
    printInOrderTree(root->right);
}

void printPostOrderTree(struct BTNode *root)
{
    if(root == NULL)
        return NULL;

    printPostOrderTree(root->left);
    printPostOrderTree(root->right);
    printf("%d ", root->data);

}

void searchTree(struct BTNode *root, int data)
{
    if(root == NULL)
        printf("%d is not in tree.\n");
    else if(root->data == data)
        printf("%d is in tree.\n", data);
    else if(data < root->data)
        searchTree(root->left, data);
    else
        searchTree(root->right, data);
}

int findMinEleTree(struct BTNode *root)
{
    struct BTNode *temp = root;

    while(temp->left != NULL)
        temp = temp->left;

    return temp->data;
}

int findMaxEleTree(struct BTNode *root)
{
    struct BTNode *temp = root;

    while(temp->right != NULL)
        temp = temp->right;

    return temp->data;
}

struct BTNode *deleteNode(struct BTNode *root, int data)
{
    if(root == NULL)
        return NULL;
    if(root->data > data)
        root->left = deleteNode(root->left, data);
    else if(root->data < data)
        root->right = deleteNode(root->right, data);
    else //if (root->data == data)
    {
        if(root->left == NULL && root->right == NULL) //case 1
        {
            free(root);
            root = NULL; //for base case
        }
        else if(root->right == NULL) //case 2 for right
        {
            struct BTNode *temp;
            temp = root;
            root = root->left;
            free(temp);
        }
        else if(root->left == NULL) //case 2 for left
        {
            struct BTNode *temp;
            temp = root;
            root = root->right;
            free(temp);
        }
        else  //case 3
        {
            struct BTNode *temp = findMinEleTree(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
};

int main()
{
    struct BTNode *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 8);
    root = insertNode(root, 14);
    root = insertNode(root, 12);
    root = insertNode(root, 16);

    printInOrderTree(root);

    printf("\n");

    printPreOrderTree(root);

    printf("\n");

    printPostOrderTree(root);

    printf("\n");

    searchTree(root, 6);

    printf("\n");

    searchTree(root, 7);

    printf("\n");

    int min = findMinEleTree(root);

    printf("The minimum element of the tree is %d\n", min);

    printf("\n");

    int max = findMaxEleTree(root);

    printf("The maximum element of the tree is %d\n", max);

    root = deleteNode(root, 4);

    printInOrderTree(root);

    printf("\n");

    return 0;
}
