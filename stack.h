#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <string.h>

#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED


struct StackNode* newNode(char data[]);

int isEmpty(struct StackNode *root);

void pushNum(struct StackNode** root, char data[]);

int popStack(struct StackNode** root);

void peek(struct StackNode* root); 

struct StackNode* newAddressNode(char *address,char chr[]);

struct StackNode* newVariableNode(char data[]) ;

int popNum(struct StackNode** root);

void pushRvalue(struct StackNode** root, char data[],int num) ;

void pushLvalue(struct StackNode** root,char chr[]) ;

// char* popAddress(struct StackNode** root);
#endif // LINKEDSTACK_H_INCLUDED

