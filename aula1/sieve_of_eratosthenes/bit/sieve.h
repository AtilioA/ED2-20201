#ifndef _SIEVE_H_
#define _SIEVE_H_
#include <stdbool.h>

void set_bit(uint8_t *bitArray, int n);
void clear_bit(uint8_t *bitArray, int n);

void init_sieve(uint8_t *bitArray, int size);
void mark_primes(uint8_t *bitArray, int size);
void print_primes(uint8_t *bitArray, int size);

#endif
