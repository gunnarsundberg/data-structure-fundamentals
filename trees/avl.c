// Gunnar Sundberg
// Florida Polytechnic University
// COP 4415 - Data Structures

#include <stdio.h>
#include <stdlib.h>

struct AVLNode
{
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

struct AVLNode * rightRotation(struct AVLNode *node)
{
    struct AVLNode *left = node->left;
    struct AVLNode *leftRight = left->right;

    left->right = node;
    node->left = leftRight;

    left->height = max((getHeight(left->left)), (getHeight(left->right))) + 1;
    node->height = max((getHeight(node->left)), (getHeight(node->right))) + 1;

    return left;
};

struct AVLNode * leftRotation(struct AVLNode *node)
{
    struct AVLNode *right = node->right;
    struct AVLNode *rightLeft = right->left;

    right->left = node;
    node->right = rightLeft;

    right->height = max((getHeight(right->left)), (getHeight(right->right))) + 1;
    node->height = max((getHeight(node->left)), (getHeight(node->right))) + 1;

    return right;
};

int getHeight(struct AVLNode *node)
{
    if(node == NULL)
        return 0;
    else
        return node->height;
}

int getBalanceFactor(struct AVLNode *root)
{
    if(root == NULL)
        return 0;
    return (getHeight(root->left)) - (getHeight(root->right));
}

struct AVLNode * insertNodeAVL(struct AVLNode *root, int newData)
{
    if(root == NULL)
    {
        struct AVLNode *newNode;
        newNode = (struct AVLNode *) malloc(sizeof(struct AVLNode));
        newNode->data = newData;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }
    else if(newData > root->data)
    {
        root->right = insertNodeAVL(root->right, newData);
    }
    else if(newData < root->data)
    {
        root->left = insertNodeAVL(root->left, newData);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalanceFactor(root);

    if(balance < -1)
    {
        if(newData > root->right->data) // right right case
            return leftRotation(root);
        else  //right left case
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }

    if(balance > 1)
    {
        if(newData < root->left->data) // left left case
            return rightRotation(root);
        else  //right left case
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }

    return root;
}

void printInOrderTree(struct AVLNode *root)
{
    if(root == NULL)
        return NULL;

    printInOrderTree(root->left);
    printf("%d ", root->data);
    printInOrderTree(root->right);
}

int main()
{
    struct AVLNode *root = NULL;
    root = insertNodeAVL(root, 1);
    root = insertNodeAVL(root, 3);
    root = insertNodeAVL(root, 5);

    printInOrderTree(root);

    printf("\n");

    root = insertNodeAVL(root, 7);

    printInOrderTree(root);

    printf("\n");

    root = insertNodeAVL(root, 9);

    printInOrderTree(root);

    printf("\n");

    root = insertNodeAVL(root, 4);

    printInOrderTree(root);

    printf("\n");

    return 0;
}
