#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    Node *listOfNumbers;

    printf("N = %i:\n\n", N);
    listOfNumbers = init_sieve(N);

    // printf("\nPrinting list:\n");
    // print_list(listOfNumbers, N);

    printf("\nMarking primes...\n");
    mark_primes(listOfNumbers, N);
    // printf("\nPrinting primes:\n");
    print_primes(listOfNumbers, N);

    // printf("\nDestroying list...\n");
    // destroy_sieve(listOfNumbers);
}
