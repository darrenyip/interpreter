#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <string.h>

#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED


struct StackNode* newNode(char data[]);

int isEmpty(struct StackNode *root);

void pushNum(struct StackNode** root, char data[]);

void popStack(struct StackNode** root);

void peek(struct StackNode* root); 

int popNum(struct StackNode** root);

void pushRvalue(struct StackNode** root, char data[]) ;

void pushLvalue(struct StackNode** root, char data[]);

#endif // LINKEDSTACK_H_INCLUDED

