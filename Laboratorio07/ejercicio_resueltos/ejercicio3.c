/* Busca un valor*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;
/* Inserta al final */
void insertNode(Node *head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}
/* Imprime un nodo */
void printNode(Node *node)
{
    printf("-----------------------------\n");
    printf("Direccion : %p\n", node);
    printf("Valor : %d\n", node->value);
    printf("Next : %p\n", node->next);
    printf("-----------------------------\n");
}
/* Recorre toda la lista */
void printList(Node *head)
{
    Node *current = head->next;
    while (current != NULL)
    {
        printNode(current);
        current = current->next;
    }
    printf("NULL\n");
}
Node *searchNode(Node *head, int value)
{
    Node *current = head->next;
    while (current != NULL)
    {
        if (current->value == value)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
/* Elimina un valor */
void deleteNode(Node *head, int value)
{
    Node *previous = head;
    Node *current = head->next;
    while (current != NULL)
    {
        if (current->value == value)
        {
            previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}
int main()
{
    /* Nodo cabecera */
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);
    printf("Lista original:\n");
    printList(head);
    deleteNode(head, 40);
    printf("Lista después de eliminar 40:\n");
    printList(head);
     printf("Buscando 40\n");
    Node *result = searchNode(head, 40);
    if (result != NULL)
    {
        printf("Nodo encontrado:\n");
        printNode(result);
    }
    else
    {
        printf("Nodo no encontrado.\n");
    }
    return 0;
}