
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]), cont_menor = 0, tam_array = N;
    Item *array;
    array = (Item *)malloc(sizeof(Item) * tam_array);

    srand(time(NULL));

    printf("Numbers (keys):\n");
    for (int i = 0; i < N; i++)
    {
        array[i] = (Item)rand() % 1000;
        printf("%i ", key(array[i]));
    }

    printf("\nOrdered array:\n");
    sort(array, 0, N);

    for (int i = 0; i < N; i++)
    {
        printf("%i ", key(array[i]));
    }

    return 0;
}
