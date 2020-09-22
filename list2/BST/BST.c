#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

BST *create_BST()
{
    BST *new = (BST *)malloc(sizeof(BST));
    (*new) = NULL;
    return new;
}

int insert_BST(BST *root, int value)
{
    if (root != NULL)
    {
        Node *new = malloc(sizeof(Node));
        new->left = NULL;
        new->right = NULL;
        new->info = value;
        Node *aux = (*root);

        if ((*root) == NULL)
        {
            (*root) = new;
            return 1;
        }

        while (aux->left != NULL || aux->right != NULL)
        {
            if (value < aux->info)
            {
                if (aux->left == NULL)
                {
                    break;
                }
                aux = aux->left;
            }
            else if (value > aux->info)
            {
                if (aux->right == NULL)
                {
                    break;
                }
                aux = aux->right;
            }
            else
            {
                return 0; // Value already present in tree
            }
        }

        if (value < aux->info)
        {
            aux->left = new;
            return 1;
        }
        else if (value > aux->info)
        {
            aux->right = new;
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

void preOrder_BST(BST *root)
{
    if (root != NULL)
    {
        printf("%d\n", (*root)->info);
        if ((*root)->left != NULL)
        {
            preOrder_BST(&((*root)->left));
        }
        if ((*root)->right != NULL)
        {
            preOrder_BST(&((*root)->right));
        }
    }
}

void inOrder_BST(BST *root)
{
    if (root != NULL)
    {
        if ((*root)->left != NULL)
        {
            inOrder_BST(&((*root)->left));
        }
        printf("%d\n", (*root)->info);
        if ((*root)->right != NULL)
        {
            inOrder_BST(&((*root)->right));
        }
    }
}

void postOrder_BST(BST *root)
{
    if (root != NULL)
    {
        if ((*root)->left != NULL)
        {
            postOrder_BST(&((*root)->left));
        }
        if ((*root)->right != NULL)
        {
            postOrder_BST(&((*root)->right));
        }
        printf("%d\n", (*root)->info);
    }
}

void preOrder(BST *root)
{
    printf("Printing preorder: %i.\n", (*root)->info);
}

void rec_preOrder_BST(BST *root, void (*visit)(BST *))
{
    if (root != NULL)
    {
        visit(root);
        if ((*root)->left != NULL)
        {
            rec_preOrder_BST(&((*root)->left), visit);
        }
        if ((*root)->right != NULL)
        {
            rec_preOrder_BST(&((*root)->right), visit);
        }
    }
}

void inOrder(BST *root)
{
    printf("Printing inorder: %i.\n", (*root)->info);
}

void rec_inOrder_BST(BST *root, void (*visit)(BST *))
{
    if (root != NULL)
    {
        if ((*root)->left != NULL)
        {
            rec_inOrder_BST(&((*root)->left), visit);
        }
        visit(root);
        if ((*root)->right != NULL)
        {
            rec_inOrder_BST(&((*root)->right), visit);
        }
    }
}

void postOrder(BST *root)
{
    printf("Printing postorder: %i.\n", (*root)->info);
}

void rec_postOrder_BST(BST *root, void (*visit)(BST *))
{
    if (root != NULL)
    {
        if ((*root)->left != NULL)
        {
            rec_postOrder_BST(&((*root)->left), visit);
        }
        if ((*root)->right != NULL)
        {
            rec_postOrder_BST(&((*root)->right), visit);
        }
        visit(root);
    }
}

int consult_BST(BST *root, int value)
{
    Node *aux = (*root);
    if (root != NULL)
    {
        while (aux->left != NULL || aux->right != NULL)
        {
            if (value < aux->info)
            {
                if (aux->left == NULL)
                {
                    break;
                }
                aux = aux->left;
            }
            else if (value > aux->info)
            {
                if (aux->right == NULL)
                {
                    break;
                }
                aux = aux->right;
            }
            else
            {
                return 1; // Value already present in tree
            }
        }

        return 0;
    }
    else
    {
        return 1;
    }

    return 0;
}

/* Free BST in post order */
void free_BST(BST *root)
{
    if (root != NULL)
    {
        if ((*root)->left != NULL)
        {
            free_BST(&((*root)->left));
        }
        if ((*root)->right != NULL)
        {
            free_BST(&((*root)->right));
        }
        free((*root));
    }
}

int calculate_BST_height(BST *root)
{
    if (root != NULL)
    {
        if (*root == NULL)
        {
            return -1;
        }
        else
        {
            int leftSide, rightSide;
            leftSide = calculate_BST_height(&((*root)->left));
            rightSide = calculate_BST_height(&((*root)->right));
            if (leftSide > rightSide)
            {
                return leftSide + 1;
            }
            else
            {
                return rightSide + 1;
            }
        }
    }
}
