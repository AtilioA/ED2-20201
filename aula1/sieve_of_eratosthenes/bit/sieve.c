#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "sieve.h"

#define BYTE 8

void set_bit(uint8_t *bitArray, int n)
{
    bitArray[n / BYTE] = bitArray[n / BYTE] | (1U << n % BYTE);
}

void clear_bit(uint8_t *bitArray, int n)
{
    bitArray[n / BYTE] = bitArray[n / BYTE] & ~(1U << n % BYTE);
}

void init_sieve(uint8_t *bitArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        set_bit(bitArray, i);
    }
}

void mark_primes(uint8_t *bitArray, int size)
{
    for (int i = 2; i <= size / 2; i++)
    {
        for (int j = 2; (i * j) <= size; j++)
        {
            if ((i * j) <= size)
            {
                clear_bit(bitArray, (i * j) - 2);
            }
        }
    }
}

void print_primes(uint8_t *bitArray, int size)
{
    for (int i = 2; i < size; i++)
    {
        if ((bitArray[(i - 2) / 8] >> (i - 2) % 8) & 0x01)
        {
            printf("%i is a prime number.\n", i);
        }
    }
}