#include <stdlib.h>
#include "item.h"
#include "insertion_sort.h"

#define SZ2 (sz + sz)
#define MIN(X, Y) ((X < Y) ? (X) : (Y))

void merge(Item *a, Item *aux, int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++)
    {
        aux[k] = a[k]; // Copy array
    }

    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
    { // Merge
        if (i > mid)
        {
            a[k] = aux[j++];
        }
        else if (j > hi)
        {
            a[k] = aux[i++];
        }
        else if (less(aux[j], aux[i]))
        {
            a[k] = aux[j++];
        }
        else
        {
            a[k] = aux[i++];
        }
    }
}

void merge_sort(Item *a, Item *aux, int lo, int hi)
{
<<<<<<< HEAD
    int CUTOFF = hi;
=======
    int CUTOFF = 5;
>>>>>>> b31749e9ed72ceffa75afd621aab9c2e15a9a0ee

    if (hi <= lo + CUTOFF - 1)
    {
        insert_sort(a, lo, hi);
        return;
    }
<<<<<<< HEAD

=======

>>>>>>> b31749e9ed72ceffa75afd621aab9c2e15a9a0ee
    int mid = lo + (hi - lo) / 2; // Avoid overflow.
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi)
{
    int N = (hi - lo) + 1;
    int y = N - 1;
    Item *aux = malloc(N * sizeof(Item));
    for (int sz = 1; sz < N; sz = SZ2)
    {
        for (int lo = 0; lo < N - sz; lo += SZ2)
        {
            int x = lo + SZ2 - 1;
            merge(a, aux, lo, lo + sz - 1, MIN(x, y));
        }
    }
    free(aux);
<<<<<<< HEAD
}
=======
}
>>>>>>> b31749e9ed72ceffa75afd621aab9c2e15a9a0ee
