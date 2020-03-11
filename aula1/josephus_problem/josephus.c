#include <stdio.h>
#include <stdlib.h>
#include "josephus.h"

void create_list(LinkedList *list)
{
    list->first = (Node *)malloc(sizeof(Node));
    list->last = list->first;
    list->first->prox = NULL;
    list->size = 0;
}

LinkedList *initialize_list(int N)
{
    LinkedList *list = malloc(sizeof(LinkedList));
    create_list(list);

    for (int i = 1; i <= N; i++)
    {
        insert_list(i, list);
    }
    return list;
}

int is_empty_list(LinkedList *list)
{
    if (list->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_valid_list(LinkedList *list)
{
    if (list->first != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert_list(int x, LinkedList *list)
{
    if (is_valid_list(list))
    {
        list->last->prox = (Node *)malloc(sizeof(Node));
        list->last = list->last->prox;
        list->last->item = x;
        list->last->prox = list->first;
        list->size++;
    }
}

void remove_list(Node *p, LinkedList *list, int *item)
{
    if (is_valid_list(list) && p != NULL)
    {
        Node *removedNode;

        removedNode = p->prox;
        *item = removedNode->item;
        p->prox = removedNode->prox;

        if (p->prox == NULL)
        {
            list->last = p;
        }

        free(removedNode);
        list->size--;
    }
}

void delete_from_list(LinkedList *list, int person)
{
    Node *current, *previous;

    previous = list->first;
    for (current = list->first->prox; current != NULL; current = current->prox)
    {
        if (current->item == person)
        {
            previous->prox = current->prox;
            free(current);
            list->size--;
            return;
        }
        previous = current;
    }
}

void print_list(LinkedList *list)
{
    Node *atual = list->first->prox;

    printf("List size: %i\n", list->size);

    for (int i = 0; i < list->size; i++)
    {
        printf("%i\n", atual->item);
        atual = atual->prox;
    }
}

void destroy_list(LinkedList *list)
{
    Node *atual = list->first;

    for (int i = 0; i < list->size; i++)
    {
        list->first = atual;
        atual = list->first->prox;

        list->size = 0;
        free(list->first);
    }
}

Node *remove_one(LinkedList *list, Node *initialNode, int M)
{
    Node *removedNode = initialNode;

    for (int i = 0; i < M; i++)
    {
        removedNode = removedNode->prox;
    }

    Node *save = malloc(sizeof(Node));
    *save = *removedNode;

    delete_from_list(list, removedNode->item);
    save = save->prox;

    return save;
}

void pick_leader(LinkedList *list, int M)
{
    Node *initialNode = remove_one(list, list->first, M);
    while (list->size > 1)
    {
        remove_one(list, initialNode, M);
    }
    printf("==============\nVENCEDOR: %i\n", list->first);
}
