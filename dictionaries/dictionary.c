#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct hash
{
    int key;
    int value;
};

struct hash hashTable[SIZE];

int hashCode(int key)
{
    return key % SIZE;
}

void insertHash(int key, int value)
{
    int hashKey = hashCode(key);

    while(hashTable[hashKey].key > 0)
    {
        hashKey++;
        hashKey = hashCode(hashKey);
    }

    hashTable[hashKey].value = value;
    hashTable[hashKey].key = key;
}

void deleteValue(int key)
{
    int hashKey = hashCode(key);

    while(hashTable[hashKey].key > 0)
    {
        if(hashTable[hashKey].key == key)
        {
             hashTable[hashKey].key = -1;
        }
        else
        {
            hashKey++;
            hashKey = hashCode(hashKey);
        }
    }
}

void printTable()
{
    printf("\nThe contents of the hash table:\n");
    
    for(int i=0; i<SIZE; i++)
    {
        if(hashTable[i].key > 0)
        printf("Index: %d, Key: %d, Value: %d\n", i, hashTable[i].key, hashTable[i].value);
    }
}

int main()
{
    insertHash(1,1);
    insertHash(2,2);
    insertHash(42,3);
    //insertHash();

    printTable();
}