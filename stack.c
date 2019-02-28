// C program for linked list implementation of stack 
#include "stack.h"


// A structure to represent a stack 
struct StackNode 
{   
    int num;
    char data[255]; 
    struct StackNode* next; 
}; 

struct StackNode* newNode(char data[]) 
{ 
    int len;
    len = strlen(data);
    if(data[len-1] == '\n') data[len-1] = 0;
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode)); 
    // stackNode->data = data;
    strcpy(stackNode->data,data);
    stackNode->next = NULL; 
    return stackNode; 
} 

int isEmpty(struct StackNode *root) 
{ 
    return !root; 
} 

void pushNum(struct StackNode** root, char data[]) 
{   
    struct StackNode* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
    printf("%s pushed to stack\n", data); 
} 
void pushRvalue(struct StackNode** root, char data[]) 
{   
    struct StackNode* stackNode = newNode("0"); 
    stackNode->next = *root; 
    *root = stackNode; 
    printf("%s pushed to stack\n", data); 
} 

char* pop(struct StackNode** root) 
{ 
    if (isEmpty(*root)) {
        printf("Empty stack! the number returned is 0\n");
        return '0'; 
    }

    struct StackNode* temp = *root; 
    *root = (*root)->next; 
    // char popped = temp->data; 
    char poped[255];
    strcpy(poped,temp->data);
    // printf("stack tempData %c -- %s\n",temp->data,temp->data);;
    free(temp); 

    return poped; 
} 

int popNum(struct StackNode** root){
    if (isEmpty(*root)) {
        printf("Empty stack! the number returned is 0\n");
        return '0'; 
    }
    struct StackNode* temp = *root; 
    *root = (*root)->next; 
    int number = atoi(temp->data);    
    printf("pop:%d\n",number);
    free(temp); 
    return number; 
} 

char peek(struct StackNode* root) 
{ 
    if (isEmpty(root)) {
        return '0'; 
    }
    int number = atoi(root->data);
    printf("print:%d\n",number);
    return root->data; 
} 
