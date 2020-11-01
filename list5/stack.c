#include "stack.h"

struct element
{
	int element;
	struct element *next;
};

struct stack
{
	int height;
	Element *head;
};

Stack *create_stack()
{
	Stack *stack = malloc(sizeof(Stack));

	stack->height = 0;
	stack->head = NULL;

	return stack;
}

Element *create_element(int integer)
{
	Element *element = malloc(sizeof(Element));

	element->element = integer;
	element->next = NULL;

	return element;
}

void push(Stack *stack, int integer)
{
	Element *element = create_element(integer);
	if (stack->head == NULL)
	{
		stack->head = element;
		stack->height = 1;
	}
	else
	{
		element->next = stack->head;
		stack->head = element;
		stack->height++;
	}
}

int pop(Stack *stack)
{
	Element *elementPointer = stack->head;

	stack->head = stack->head->next;
	stack->height -= 1;
	elementPointer->next = NULL;

	return elementPointer->element;
}

void free_stack(Stack *stack)
{
	Element *elementPointer;

	for (int i = 0; i < stack->height; i++)
	{
		elementPointer = stack->head;
		stack->head = stack->head->next;
		free(elementPointer);
	}

	free(stack);
}

int stack_empty(Stack *stack)
{
	return stack->height <= 0;
}
