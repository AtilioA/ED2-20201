#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int main(int argc, char *argv[])
{
    Queue *queue = create_queue();

    int N = atoi(argv[1]), i = 0, data[N];
    srand(time(NULL));

    printf("Numbers:\n");
    for (i = 0; i < N; i++)
    {
        data[i] = rand() % 1000;
        printf("%i ", data[i]);
    }

    for (i = 0; i < N; i++)
    {
        queue_insert(queue, &data[i]);
    }
    
    print_queue(queue, INT);

    delete_queue(queue);

    return 0;
}