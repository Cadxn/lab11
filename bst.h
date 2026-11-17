#include <stdbool.h>
#include "itemType.h"

#ifndef BST_H
#define BST_H

typedef struct bstType *bst;

bst createBST();
void freeBST(bst);

void insertItem(bst,itemType);
void removeItem(bst,itemType);

bool contains(bst,itemType);

void preorder(bst,void (*f)(itemType));
void inorder(bst,void (*f)(itemType));
void postorder(bst,void (*f)(itemType));

int size(bst);
bool isEmpty(bst);
#endif