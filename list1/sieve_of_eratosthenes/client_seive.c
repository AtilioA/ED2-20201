#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int *array = init_sieve(N);

    printf("N = %i:\n\n", N);

    // printf("\nPrinting list:\n");
    // print_array(array, N);

    // printf("\nMarking primes...\n");
    mark_primes(array, N);
    // printf("\nPrinting primes:\n");
    // print_primes(array, N);

    // printf("\nDestroying list...\n");
    free(array);
}
