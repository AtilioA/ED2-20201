#ifndef __STACK_H
#define __STACK_H

#include "stdio.h"
#include "stdlib.h"

typedef struct stack Stack;
typedef struct item Item;

enum elementTypes
{
    INT = 1
};

Stack *create_stack();

void push(Stack *stack, void *item);
Item *pop(Stack *stack);

void print_stack(Stack *stack, int type);
void delete_stack(Stack *stack);

Item *stack_head(Stack *stack);
int stack_height(Stack *stack);

#endif