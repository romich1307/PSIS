#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 10
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
int hashFunction(int value)
{
    return value % HASH_SIZE;
}
void insertHash(Node *hashTable[], int value)
{
    int index = hashFunction(value);
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
        return;
    }
    Node *current = hashTable[index];
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}
Node *searchHash(Node *hashTable[], int value)
{
    int index = hashFunction(value);
    Node *current = hashTable[index];
    while (current != NULL)
    {
        if (current->value == value)
            return current;
        current = current->next;
    }
    return NULL;
}
void printHash(Node *hashTable[])
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        printf("[%d] -> ", i);
        Node *current = hashTable[i];
        while (current != NULL)
        {
            printf("%d -> ", current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    Node *hashTable[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++)
        hashTable[i] = NULL;
    insertHash(hashTable, 21);
    insertHash(hashTable, 31);
    insertHash(hashTable, 13);
    insertHash(hashTable, 9);
    insertHash(hashTable, 14);
    printHash(hashTable);
    Node *node = searchHash(hashTable, 31);
    if (node != NULL)
        printf("\nEncontrado: %d\n", node->value);
    return 0;
}