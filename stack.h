#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED


struct StackNode* newNode(char data);
int isEmpty(struct StackNode *root);
void push(struct StackNode** root, char data);
char pop(struct StackNode** root);
char peek(struct StackNode* root); 


#endif // LINKEDSTACK_H_INCLUDED