#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <stdio.h>

typedef struct Node *BST; // root

BST *create_BST();
int insert_BST(BST *root, int value);

void levelOrder_print(BST *root);
void levelOrder_traversal(BST *root, void (*visit)(BST *));

int consult_BST(BST *root, int value);
int calculate_BST_height(BST *root);
void free_BST(BST *root);

#endif
