#include <stdlib.h>
#include <time.h>
#include "insertion_sort.h"
#include "stack.h"

Stack *stack;

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
    stack = create_stack();
    push(stack, lo);
    push(stack, hi);
    while (!stack_empty(stack))
    {
        lo = pop(stack);
        hi = pop(stack);
        if (lo + CUTOFF - 1 >= hi)
        {
            insert_sort(array, lo, hi);
            return;
        }
        int i = partition(array, lo, hi);
        if (i - lo > hi - i)
        {                    // Test the size of sub-arrays.
            push(stack, lo); // Push the larger one.
            push(stack, i - 1);

            push(stack, i + 1); // Sort the smaller one first.
            push(stack, hi);
        }
        else
        {
            push(stack, i + 1);
            push(stack, hi);

            push(stack, lo);
            push(stack, i - 1);
        }
    }
}

void sort(Item *array, int lo, int hi)
{
    quick_sort(array, lo, hi);
}
