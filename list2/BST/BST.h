#ifndef __ARVORE_BINARIA_H
#define __ARVORE_BINARIA_H

#include <stdio.h>

typedef struct Node *BST; // root

BST *create_BST();
int insert_BST(BST *root, int value);
void preOrder(BST *root);
void inOrder(BST *root);
void postOrder(BST *root);
void preOrder_BST(BST *root);
void inOrder_BST(BST *root);
void postOrder_BST(BST *root);
void rec_preOrder_BST(BST *root, void (*visit)(BST *));
void rec_inOrder_BST(BST *root, void (*visit)(BST *));
void rec_postOrder_BST(BST *root, void (*visit)(BST *));
int consult_BST(BST *root, int value);
int calculate_BST_height(BST *root);
void free_BST(BST *root);

#endif
