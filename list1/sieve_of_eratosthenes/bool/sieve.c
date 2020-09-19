#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sieve.h"

bool *init_sieve(int size)
{
    bool *array = (bool *)malloc(sizeof(bool) * size);

    for (int i = 0; i < size; i++)
    {
        array[i] = true;
    }

    return array;
}

void mark_primes(bool *array, int size)
{
    for (int i = 2; i <= size / 2; i++)
    {
        if (array[i])
        {
            for (int j = 2; (i * j) <= size; j++)
            {
                if ((i * j) <= size)
                {
                    array[(i * j) - 2] = false;
                }
            }
        }
    }
}

void print_array(bool *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%i\n", i);
    }
}

void print_primes(bool *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (!array[i])
        {
            printf("%i is a prime number.\n", i);
        }
    }
}
