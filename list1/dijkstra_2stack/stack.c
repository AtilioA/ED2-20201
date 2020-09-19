#include "stack.h"

struct item
{
	int id;
	void *item;
	struct item *next;
};

struct stack
{
	int height;
	Item *head;
};

Stack *create_stack()
{
	Stack *stack = malloc(sizeof(Stack));

	stack->height = 0;
	stack->head = NULL;

	return stack;
}

Item *create_item(int type, void *element)
{
	Item *item = malloc(sizeof(Item));

	item->id = type;
	item->item = element;
	item->next = NULL;

	return item;
}

void push(Stack *stack, Item *item)
{
	if (stack->head == NULL)
	{
		stack->head = item;
		stack->height = 1;
	}
	else
	{
		item->next = stack->head;
		stack->head = item;
		stack->height++;
	}
}

Item *pop(Stack *stack)
{
	Item *itemPointer = stack->head;

	stack->head = stack->head->next;
	stack->height -= 1;
	itemPointer->next = NULL;

	return itemPointer;
}

void print_stack(Stack *stack)
{
	Item *itemPointer = stack->head;

	for (int i = 0; i < stack->height; i++)
	{
		if (itemPointer->id == OPERAND)
		{
			double *itemValue = itemPointer->item;
			printf("%.2lf ", *itemValue);
		}
		else
		{
			char *itemChar = itemPointer->item;
			printf("%c ", *itemChar);
		}
		itemPointer = itemPointer->next;
	}
	printf("\n");
}

int is_operator(char *c)
{
	switch (*c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

double compute_values(Item *operand, Item *operand2, Item *operator)
{
	double *item1 = operand->item;
	double *item2 = operand2->item;
	char *operatorChar = operator->item;
	double result;

	switch (*operatorChar)
	{
	case '+':
		result = *item1 + *item2;
		break;
	case '-':
		result = *item1 - *item2;
		break;
	case '*':
		result = *item1 * *item2;
		break;
	case '/':
		result = *item1 / *item2;
		break;
	default:
		result = *item1 + *item2;
	}

	return result;
}

void free_stack(Stack *stack)
{
	Item *itemPointer;

	for (int i = 0; i < stack->height; i++)
	{
		itemPointer = stack->head;
		stack->head = stack->head->next;
		free(itemPointer);
	}

	free(stack);
}
