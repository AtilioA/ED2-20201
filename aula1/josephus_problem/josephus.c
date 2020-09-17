#include <stdio.h>
#include <stdlib.h>
#include "josephus.h"

void create_list(LinkedList *list)
{
    list->first = (Node *)malloc(sizeof(Node));
    list->last = list->first;
    list->first->next = NULL;
    list->size = 0;
}

LinkedList *initialize_list(int N)
{
    LinkedList *list = malloc(sizeof(LinkedList));
    create_list(list);

    Node *previous, *node = malloc(sizeof(Node));
    node->item = 1;
    list->first = node;
    list->size++;

    for (int i = 2; i <= N; i++)
    {
        node->next = malloc(sizeof(Node));
        previous = node;
        node = node->next;
        node->item = i;
        node->prev = previous;
        list->size++;
    }

    list->last = node;
    list->last->next = list->first;
    list->first->prev = list->last;

    return list;
}

void delete_from_list(LinkedList *list, Node *removedNode){
    if (list->first == list->last)
    {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        list->size--;
        return;
    }

    if (removedNode == list->first)
    {
        list->first = removedNode->next;
    }
    if (removedNode == list->last)
    {
        list->last = list->last->prev;
    }

    removedNode->prev->next = removedNode->next;
    removedNode->next->prev = removedNode->prev;
    list->size--;

    free(removedNode);
}

void print_list(LinkedList *list)
{
    Node *current = list->first;

    printf("List size: %i.\n", list->size);

    for (int i = 0; i < list->size; i++)
    {
        printf("%i\n", current->item);
        current = current->next;
    }
}

int select_leader(LinkedList *list, int m){
    Node *current = list->first;

    while (list->size > 1)
    {
        for (int i = 0; i < m - 1; i++)
        {
            current = current->next;
        }

        Node *previous = current;
        current = current->next;
        delete_from_list(list, previous);
    }

    return list->first->item;
}

void destroy_list(LinkedList *list)
{
    Node *atual = list->first;

    for (int i = 0; i < list->size; i++)
    {
        list->first = atual;
        atual = list->first->next;

        free(list->first);
    }

    list->size = 0;
    free(list);
}
