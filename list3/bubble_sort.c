#include "item.h"

void sort(Item *array, int lo, int hi)
{
    for (int current_sort = lo; current_sort < hi; current_sort++)
    {
        for (int scan_array = hi - 1; scan_array > current_sort; scan_array--)
        {
            compexch(array[current_sort], array[scan_array + 1]);
        }
    }
}
