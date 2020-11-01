#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "insertion_sort.h"

int partition(Item *array, int lo, int hi)
{
    int i = lo, j = hi + 1;
    Item v = array[lo];

    while (1)
    {
        while (less(array[++i], v)) // Find item on left to swap.
        {
            if (i == hi)
            {
                break;
            }
        }

        while (less(v, array[--j])) // Find item on right to swap.
        {
            if (j == lo)
            {
                break;
            }
        }

        if (i >= j) // Check if pointers cross.
        {
            break;
        }
        exch(array[i], array[j]);
    }

    exch(array[lo], array[j]); // Swap with partitioning item.

    return j; // Return index of item known to be in place.
}

void quick_sort(Item *array, int lo, int hi)
{
    const int CUTOFF = 10;
    if (lo + CUTOFF - 1 >= hi)
    {
        insert_sort(array, lo, hi);
        return;
    }

    int j = partition(array, lo, hi);
    quick_sort(array, lo, j - 1);
    quick_sort(array, j + 1, hi);
}

void sort(Item *array, int lo, int hi)
{
    quick_sort(array, lo, hi);
}
