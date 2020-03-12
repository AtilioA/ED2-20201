#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main2()
{
    int i = 0, N = 8, data[8] = {50, 100, 30, 20, 40, 45, 35, 37};

    BST *root = create_BST();

    for (i = 0; i < N; i++)
    {
        insert_BST(root, data[i]);
    }
    printf("Inserted data into the tree.\n");

    int element = 35;
    if (consult_BST(root, element))
    {
	    printf("Found element %d.\n", element);
    }
    else
    {
	    printf("Element %d not found.\n", element);
    }

    inOrder_BST(root);
    printf("\n");
    preOrder_BST(root);
    printf("\n");
    postOrder_BST(root);
    printf("\n");

    free_BST(root);
    free(root);

    return 0;
}
