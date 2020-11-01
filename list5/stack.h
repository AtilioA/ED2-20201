#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element Element;
typedef struct stack Stack;

Stack *create_stack();
Element *create_element(int element);

void push(Stack *stack, int integer);
int pop(Stack *);

void free_stack(Stack *);
int stack_empty(Stack *);

#endif
