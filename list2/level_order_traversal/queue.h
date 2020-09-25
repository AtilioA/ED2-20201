#ifndef __QUEUE_H
#define __QUEUE_H

#include "stdio.h"
#include "stdlib.h"

typedef struct queue Queue;
typedef struct item Item;

enum elementTypes
{
    INT = 1
};

Queue *create_queue();

void queue_insert(Queue *queue, void *item);
Item *dequeue(Queue *queue);

void print_queue(Queue *queue, int type);
void delete_queue(Queue *queue);

void *get_element(Item *item);
Item *queue_first(Queue *queue);
int queue_size(Queue *queue);

#endif