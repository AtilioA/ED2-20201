#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sieve.h"

Node *init_sieve(int size)
{
    Node *node = (Node*)malloc((size - 1) * sizeof(Node));

    for (int i = 2; i <= size; i++)
    {
        node[i - 2].label = i;
        node[i - 2].marked = 0;
    }

    // printf("List initializatedson.\n");

    return node;
}

void mark_primes(Node *list, int size)
{
    for (int i = 2; i <= size / 2; i++)
    {
        for (int j = 2; (i * j) <= size; j++)
        {
            if ((i * j) <= size)
            {
                list[(i * j) - 2].marked = 1;
            }
        }
    }
}

void print_list(Node *list, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%i\n", list[i].label);
    }
}

void print_primes(Node *list, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (!list[i].marked)
        {
            printf("%i is a prime number.\n", list[i].label);
        }
    }
}

void destroy_sieve(Node *node)
{
    free(node);
}
