#include "stack.h"

struct item
{
    void *element;
    struct item *next;
};

struct stack
{
    struct item *head;
    int height;
};

Stack *create_stack()
{
    Stack *stack = malloc(sizeof(Stack));

    stack->head = NULL;
    stack->height = 0;

    return stack;
}

void push(Stack *stack, void *element)
{
    if (stack_head(stack) == NULL)
    {
        Item *item = malloc(sizeof(Item));

        item->element = element;
        item->next = NULL;
        stack->head = item;

        stack->height = 1;
    }
    else
    {
        Item *item = malloc(sizeof(Item));

        item->element = element;
        item->next = stack_head(stack);
        stack->head = item;

        stack->height += 1;
    }
}

Item *pop(Stack *stack)
{
    if (stack_head(stack) != NULL)
    {
        Item *item = stack_head(stack);

        stack->head = item->next;
        stack->height -= 1;

        return item;
    }
}

void print_stack(Stack *stack, int type)
{
    Item *itemPointer = stack_head(stack);

    printf("Stack: ");
    for (int i = 0; i < stack_height(stack) - 1; i++)
    {
        if (type == INT)
        {
            int *value = itemPointer->element;
            printf("%i - ", *value);
            itemPointer = itemPointer->next;
        }
    }
    if (type == INT)
    {
        int *value = itemPointer->element;
        printf("%i\n", *value);
    }
    printf("Height: %i\n", stack->height);
}

void delete_stack(Stack *stack)
{
    Item *itemPointer = stack_head(stack);

    for (int i = 0; i < stack_height(stack); i++)
    {
        stack->head = stack_head(stack)->next;
        free(itemPointer);
        itemPointer = stack_head(stack);
    }

    free(stack);
}

void *get_element(Item *item) {
    return item->element;
}

Item *stack_head(Stack *stack)
{
    return stack->head;
}

int stack_height(Stack *stack)
{
    return stack->height;
}