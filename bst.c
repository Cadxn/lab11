#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


struct node
{
    itemType data;
    struct node *left;
    struct node *right;
} Node;
struct bstType{
    struct node *root;
};

bst createBST(){
    bst t = malloc(sizeof(struct bstType));
    if (t != NULL) {
        t->root = NULL;
    }
    return t;
}
static void freeNodes(struct node *t) {
    if (t!=NULL) {
        freeNodes(t->left);
        freeNodes(t->right);
#ifdef NEED_TO_FREE
        freeItemType(t->data);
#endif
        printf("freeing %s\n",toItemString(t->data));
        free(t);
    }
}

void freeBST(bst t){
    if (t != NULL) {
        freeNodes(t->root);
        t->root = NULL;
    }

}
static struct node *findMin(struct node *t) {
    return ((t->left==NULL)?t:findMin(t->left));
}
static struct node *removeMin(struct node *t) {
    if(t!=NULL) {
        if(t->left!=NULL)
            t->left = removeMin(t->left);
        else {
            struct node *ptr = t;
            t = t->right;
#ifdef NEED_TO_FREE
            freeItemType(ptr->data);
#endif
            free(ptr);
        }
    }
    return t;
}
static struct node *insertNode(struct node *t, itemType item) {
    if(t==NULL) {
        t = malloc(sizeof(struct node));
        t->data = item; t->left = t->right = NULL;
    } else if(itemcmp(item,t->data) < 0)
        t->left = insertNode(t->left,item);
    else if(itemcmp(item,t->data) > 0)
        t->right = insertNode(t->right,item);
    else
        printf("Warning: duplicate item '%s' ignored\n",
               toItemString(item));
    return t;
}
void insertItem(bst t,itemType item){
     t->root = insertNode(t->root,item);
}
static struct node *removeNode(struct node *t, itemType item) {
    if(t == NULL){
        printf("Warning: item '%s' not found\n",toItemString(item));
    }
    else if(itemcmp(item,t->data) < 0)
        t->left = removeNode(t->left,item);
    else if(itemcmp(item,t->data) > 0)
        t->right = removeNode(t->right,item);
    else // found it!
        if(t->left!=NULL && t->right!=NULL) {
            t->data = findMin(t->right)->data;
            t->right = removeMin(t->right);
        } else
            t = ((t->left!=NULL)?t->left:t->right);
    return t;
}
void removeItem(bst t,itemType item){
    t->root = removeNode(t->root,item);
}
static bool containsNode(struct node *t, itemType item){
    if(t == NULL){
        return false;
    }
    else if(itemcmp(item,t->data) == 0)
        return true;
    else if(itemcmp(item,t->data) < 0)
        return containsNode(t->left,item);
    else{
        return containsNode(t->right,item);
    }
}
bool contains(bst t, itemType item) {
    if (t == NULL) return false;
    return containsNode(t->root, item);
}

static void preOrder(struct node *t,void (*f)(itemType)) {
    if(t!=NULL) {
        f(t->data);
        preOrder(t->left,f);
        preOrder(t->right,f);
    }
}

void inOrder(struct node *t,void (*f)(itemType)){
    if(t!=NULL) {
        inOrder(t->left,f);
        f(t->data);
        inOrder(t->right,f);
    }
}
void postOrder(struct node *t,void (*f)(itemType)){
    if(t!=NULL) {
        postOrder(t->left,f);
        postOrder(t->right,f);
        f(t->data);
}
}
void preorder(bst t, void (*f)(itemType)) {
    preOrder(t->root, f);
}

void inorder(bst t, void (*f)(itemType)) {
    inOrder(t->root, f);
}

void postorder(bst t, void (*f)(itemType)) {
    postOrder(t->root, f);
}

static int tcount(struct node *t) {
return ((t==NULL)?0:1+tcount(t->left)+tcount(t->right));
}
int size(bst t) { 
    return tcount(t->root); 
}

bool isEmpty(bst t) {
    return t->root==NULL;
}

