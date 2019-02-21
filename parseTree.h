#include <stdio.h>
#include <stdlib.h>

#include "tokenTable.h"
#include "util.h"

typedef struct node{
    int data;
    _bool isNum;
    struct node *leftChild;
    struct node *rightChild;
}node;
node *root;
void insert(int data,_bool isNum);
void post_order_traversal(struct node* root);
void createTree(token *head);
