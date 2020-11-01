
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

void print_array(Item *a, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    Item *array = (Item *)malloc(sizeof(Item) * N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }

    sort(array, 0, N);

    print_array(array, N);

    free(array);
}
