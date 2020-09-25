#include "queue.h"

struct item
{
    void *element;
    struct item *next;
};

struct queue
{
    struct item *first;
    struct item *last;
    int size;
};

Queue *create_queue()
{
    Queue *queue = malloc(sizeof(Queue));

    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;

    return queue;
}

void enqueue(Queue *queue, void *element)
{
    Item *item = malloc(sizeof(Item));
    item->next = NULL;

    if (queue_first(queue) == NULL)
    {
        item->element = element;

        queue->first = item;
        queue->last = queue->first;
    }
    else
    {
        item->element = element;

        queue->last->next = item;
        queue->last = queue->last->next;
    }

    queue->size++;
}

Item *dequeue(Queue *queue)
{
    if (queue_first(queue) != NULL)
    {
        Item *item = queue_first(queue);

        queue->first = item->next;
        queue->size -= 1;

        return item;
    }
}

void print_queue(Queue *queue, int type)
{
    Item *itemPointer = queue_first(queue);

    printf("Queue: ");
    for (int i = 0; i < queue_length(queue) - 1; i++)
    {
        if (type == INT)
        {
            int *value = itemPointer->element;
            printf("%i - ", *value);
            itemPointer = itemPointer->next;
        }
    }
    if (type == INT)
    {
        int *value = itemPointer->element;
        printf("%i\n", *value);
    }
    printf("Size: %i\n", queue->size);
}

void delete_queue(Queue *queue)
{
    Item *itemPointer = queue_first(queue);

    for (int i = 0; i < queue_length(queue); i++)
    {
        queue->first = queue_first(queue)->next;
        free(itemPointer);
        itemPointer = queue_first(queue);
    }

    free(queue);
}

void *get_element(Item *item)
{
    return item->element;
}

Item *queue_first(Queue *queue)
{
    return queue->first;
}

int queue_length(Queue *queue)
{
    return queue->size;
}