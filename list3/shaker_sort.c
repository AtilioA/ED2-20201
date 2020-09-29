#include "item.h"

void sort(Item *array, int lo, int hi)
{
    int swapped = 1, i = lo, aux = 0;
    while (swapped == 1 && lo < hi)
    {
        swapped = 0;

        // Forwards
        for (i = lo; i < hi; i++)
        {
            if (less(array[i], array[i + 1]))
            {
                exch(array[i], array[i + 1]);
                swapped = 1;
            }
        }
        hi--;

        // Backwards
        for (i = hi; i > lo; i = i--)
        {
            if (less(array[i], array[i - 1]))
            {
                exch(array[i], array[i + 1]);
                swapped = 1;
            }
        }
        lo++;
    }
}
