#ifndef _JOSEPHUS_H_
#define _JOSEPHUS_H_

// typedef struct item
// {
//     int chave;
// } Item;

typedef struct node
{
    int item;
    struct node *prox;
} Node;

typedef struct linked_list
{
    Node *first, *last;
    int size;
} LinkedList;

void create_list(LinkedList *list);
LinkedList *initialize_list(int N);
int is_empty_list(LinkedList *list);
int is_valid_list(LinkedList *list);
void print_list(LinkedList *list);
void insert_list(int x, LinkedList *list);
void remove_list(Node *p, LinkedList *list, int *item);
Node *remove_one(LinkedList *list, Node *initialNode, int M);
void delete_from_list(LinkedList *list, int person);
void pick_leader(LinkedList *list, int M);
void destroy_list(LinkedList *list);

#endif
