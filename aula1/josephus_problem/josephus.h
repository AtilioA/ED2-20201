#ifndef _JOSEPHUS_H_
#define _JOSEPHUS_H_

typedef struct node
{
    int item;
    struct node *prev, *next;
} Node;

typedef struct linked_list
{
    Node *first, *last;
    int size;
} LinkedList;

void create_list(LinkedList *list);
LinkedList *initialize_list(int N);
void print_list(LinkedList *list);
void delete_from_list(LinkedList *list, Node *removedNode);
int select_leader(LinkedList *list, int m);
void destroy_list(LinkedList *list);

#endif
