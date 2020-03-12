#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h"

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int i = 0, data[N];
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        data[i] = rand();
    }

    BST *root = create_BST();

    for (i = 0; i < N; i++)
    {
        insert_BST(root, data[i]);
    }
    printf("Inserted data into binary tree.\n");

    inOrder_BST(root);
    printf("\n");

    int height = calculate_BST_height(root);
    printf("Height: %i\n", height);

    free_BST(root);
    free(root);

    return 0;
}
