#include <stdlib.h>
#include <time.h>
#include "item.h"

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

Item median_of_3(Item array[], int lo, int hi)
{
    int median = (lo + hi) / 2;

    if (array[lo] > array[hi])
    {
        exch(array[lo], array[hi]);
    }
    if (array[lo] > array[median])
    {
        exch(array[lo], array[median]);
    }
    if (array[hi] > array[median])
    {
        exch(array[hi], array[median]);
    }

    return array[hi];
}

void quick_sort(Item *array, int lo, int hi)
{
    if (lo >= hi)
    {
        return;
    }

    Item median = median_of_3(array, lo, hi);
    exch(array[lo], array[median]);

    int j = partition(array, lo, hi);
    quick_sort(array, lo, j - 1);
    quick_sort(array, j + 1, hi);
}

void sort(Item *array, int lo, int hi)
{
    quick_sort(array, lo, hi);
}
