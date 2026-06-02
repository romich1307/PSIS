#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
} Node;
void insertNode(Node *head, int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    Node *current = head;
    while (current->next != NULL)
        current = current->next;
    newNode->prev = current;
    current->next = newNode;
}
Node *searchNode(Node *head, int value)
{
    Node *current = head->next;
    while (current != NULL)
    {
        if (current->value == value)
            return current;
        current = current->next;
    }
    return NULL;
}
void deleteNode(Node *node)
{
    node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    free(node);
}
void printList(Node *head)
{
    Node *current = head->next;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    head->prev = NULL;
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    printList(head);
    Node *node = searchNode(head, 20);
    if (node != NULL)
        deleteNode(node);
    printList(head);
    return 0;
}