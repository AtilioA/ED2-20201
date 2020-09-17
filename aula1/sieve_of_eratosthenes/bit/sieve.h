#ifndef _SIEVE_H_
#define _SIEVE_H_
#include <stdbool.h>

typedef struct node
{
    int label;
    unsigned marked;
} Node;

Node *init_sieve(int size);
void print_list(Node *list, int size);
void mark_primes(Node *list, int size);
void print_primes(Node *list, int size);
void destroy_sieve(Node *node);

#endif
