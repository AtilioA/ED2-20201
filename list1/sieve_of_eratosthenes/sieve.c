#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

int *init_sieve(int size)
{
    int *array = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        array[i] = 1;
    }

    return array;
}

void mark_primes(int *array, int size)
{
    for (int i = 2; i <= size / 2; i++)
    {
        if (array[i])
        {
            for (int j = 2; (i * j) <= size; j++)
            {
                if ((i * j) <= size)
                {
                    array[(i * j) - 2] = 0;
                }
            }
        }
    }
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%i\n", i);
    }
}

void print_primes(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (!array[i])
        {
            printf("%i is a prime number.\n", i);
        }
    }
}
