#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sieve.h"

#define BYTE 8

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    uint8_t *bitArray;
    bitArray = malloc((N / BYTE + 1) * sizeof(uint8_t));

    // printf("N = %i:\n\n", N);
    init_sieve(bitArray, N);

    mark_primes(bitArray, N);
    // print_primes(bitArray, N);

    free(bitArray);
}
