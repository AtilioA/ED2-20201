#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct item Item;
typedef struct stack Stack;

enum types
{
    OPERATOR = 0,
    OPERAND = 1,
};

Stack *create_stack();
Item *create_item(int, void *);

void push(Stack *, Item *);
Item *pop(Stack *);
void print_stack(Stack *);

int is_operator(char *);
double compute_values(Item *operand1, Item *operand2, Item *operator);

void free_stack(Stack *);
