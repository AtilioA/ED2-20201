#include "BST.h"
#include "stack.h"
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
    Node *nodePointer = *root;
    if (root != NULL)
    {
        Stack *stack = create_stack();
        push(stack, nodePointer);

        while (stack_height(stack) > 0)
        {
            Item *item = pop(stack);
            nodePointer = get_element(item);
            visit(&nodePointer);
            free(item);

            if (nodePointer->right != NULL)
            {
                push(stack, nodePointer->right);
            }
            if (nodePointer->left != NULL)
            {
                push(stack, nodePointer->left);
            }
        }
        delete_stack(stack);
    }
}

void inOrder(BST *root)
{
    printf("Printing inorder: %i.\n", (*root)->info);
}

void postOrder(BST *root)
{
    printf("Printing postorder: %i.\n", (*root)->info);
}

void rec_inOrder_BST(BST *root, void (*visit)(BST *))
{
    Node *nodePointer = *root;
    Stack *stack = create_stack();
    while (stack_height(stack) > 0 || nodePointer != NULL)
    {
        if (nodePointer != NULL)
        {
            push(stack, nodePointer);
            nodePointer = (nodePointer)->left;
        }
        else
        {
            Item *item = pop(stack);
            nodePointer = get_element(item);
            (*visit)(&nodePointer);
            free(item);
            nodePointer = (nodePointer)->right;
        }
    }
    delete_stack(stack);
}

void rec_postOrder_BST(BST *root, void (*visit)(BST *))
{
    Node *nodePointer = *root;
    Stack *stack = create_stack();
    Node *lastNodeVisited = NULL;

    while (stack_height(stack) > 0 || nodePointer != NULL)
    {
        if (nodePointer != NULL)
        {
            push(stack, nodePointer);
            nodePointer = nodePointer->left;
        }
        else
        {
            Item *stackHead = stack_head(stack);
            Node *nodeHead = get_element(stackHead);
            if (nodeHead->right != NULL && lastNodeVisited != nodeHead->right)
            {
                nodePointer = nodeHead->right;
            }
            else
            {
                (*visit)(&nodeHead);
                Item *item = pop(stack);
                lastNodeVisited = get_element(item);
                free(item);
            }
        }
    }

    delete_stack(stack);
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
