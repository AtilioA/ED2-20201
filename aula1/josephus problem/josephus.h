#ifndef _JOSEPHUS_H_
#define _JOSEPHUS_H_

typedef struct item
{
    int chave;
} Item;

typedef struct node
{
    Item item;
    struct node *prox;
} Node;

typedef struct linked_list
{
    Node *primeiro, *ultimo;
} LinkedList;

#endif
