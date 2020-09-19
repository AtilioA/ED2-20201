#ifndef __ARVORE_BINARIA_H
#define __ARVORE_BINARIA_H

#include <stdio.h>

typedef struct Node *BST; // root

BST* create_BST();
int insert_BST(BST *root, int value);
int consult_BST(BST* root, int value);
int calculate_BST_height(BST *root);
void free_BST(BST *root);

#endif
