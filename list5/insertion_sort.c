#include "item.h"

void insert_sort(Item *array, int lo, int hi)
{
    for (int current_sort = lo; current_sort < hi; current_sort++)
    {
        for (int scan_array = current_sort; scan_array > 0 && less(array[scan_array], array[scan_array - 1]); scan_array--)
        {
            exch(array[scan_array], array[scan_array - 1]);
        }
    }
}
