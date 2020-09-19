#ifndef _SIEVE_H_
#define _SIEVE_H_

int *init_sieve(int size);
void print_array(int *array, int size);
void mark_primes(int *array, int size);
void print_primes(int *array, int size);
void destroy_sieve(int *array);

#endif
