#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h"
#include "queue.h"

int main(int argc, char *argv[])
{
    BST *root = create_BST();

    int N = atoi(argv[1]), i = 0, data[N];
    srand(time(NULL));

    printf("Numbers:\n");
    for (i = 0; i < N; i++)
    {
        data[i] = rand() % 1000;
        printf("%i ", data[i]);
    }

    printf("\nTree:\n");
    for (i = 0; i < N; i++)
    {
        insert_BST(root, data[i]);
    }

    levelOrder_traversal(root, levelOrder_print);

    free_BST(root);

    return 0;
}