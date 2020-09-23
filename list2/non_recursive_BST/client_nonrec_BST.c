#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "BST.h"
#include "stack.h"

int main(int argc, char *argv[])
{
    Stack *stack = create_stack();

    int N = atoi(argv[1]), i = 0, data[N];
    srand(time(NULL));

    printf("Numbers:\n");
    for (i = 0; i < N; i++)
    {
        data[i] = rand() % 1000;
        printf("%i ", data[i]);
    }

    printf("\nStack:\n");
    for (i = 0; i < N; i++)
    {
        push(stack, &data[i]);
    }

    print_stack(stack, INT);

    return 0;
}

/*
int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int i = 0, data[N];
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        data[i] = rand() % 1000;
    }

    BST *root = create_BST();

    for (i = 0; i < N; i++)
    {
        insert_BST(root, data[i]);
    }
    printf("Inserted data into binary tree.\n");

    rec_inOrder_BST(root, inOrder);
    printf("\n");

    int height = calculate_BST_height(root);
    printf("Height: %i\n", height);

    free_BST(root);
    free(root);

    return 0;
}
*/