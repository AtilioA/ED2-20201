#ifndef _SIEVE_H_
#define _SIEVE_H_
#include <stdbool.h>

bool *init_sieve(int size);
void print_array(bool *array, int size);
void mark_primes(bool *array, int size);
void print_primes(bool *array, int size);
void destroy_sieve(bool *array);

#endif
