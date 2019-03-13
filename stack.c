// C program for linked list implementation of stack 
#include "stack.h"


// A structure to represent a stack 
struct StackNode 
{   
    int num;
    char *address; //store address
    char *variable; // is this stack node a variable?
    char data[255];
    struct StackNode* next; 
}; 

struct StackNode* newNode(char data[]) 
{ 
    int len;
    len = strlen(data);
    if(data[len-1] == '\n') data[len-1] = 0;
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode)); 
    strcpy(stackNode->data,data);
    stackNode->next = NULL; 
    return stackNode; 
} 

struct StackNode* newAddressNode(char *address) 
{   
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode)); 
    stackNode->address = address;
    stackNode->next = NULL; 
    strcpy(stackNode->data,"address");
    printf("address:%p -- newAddressNode()\n",stackNode->address); //pass success
    return stackNode; 
}

struct StackNode* newVariableNode(char *address) 
{   
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode)); 
    stackNode->next = NULL; 
    stackNode->variable = "variable";
    strcpy(stackNode->data,"address");
    printf("address:%p -- newAddressNode()\n",stackNode->address); //pass success
    return stackNode; 
}


void pushLvalue(struct StackNode** root, char *location) 
{   
    printf("address:%p -- pushLvalue()\n",location);
    struct StackNode* stackNode = newAddressNode(location);
    stackNode->next = *root; 
    *root = stackNode;
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

void popStack(struct StackNode** root) 
{ 
    if (isEmpty(*root)) {
        printf("Empty stack! the number returned is 0\n");
    }
    struct StackNode* temp = *root; 
    *root = (*root)->next;
    int number;
    char *address;
    if(strcmp(temp->data,"address") != 0){
        number = atoi(temp->data);  
        printf("pop:%d\n",number);
    }else{
        address = temp->address;
        printf("address:%p",address);
    }
    free(temp); 
} 

int popNum(struct StackNode** root){
    if (isEmpty(*root)) {
        printf("Empty stack! the number returned is 0\n");
    }
    struct StackNode* temp = *root; 
    *root = (*root)->next;
    int number;
    char *address;
    if(strcmp(temp->data,"address") != 0){
        number = atoi(temp->data);  
        printf("pop:%d\n",number);
    }else{
        address = temp->address;
        printf("address:%p",address);
    }
    free(temp); 
    return number; 
} 

void peek(struct StackNode* root) 
{ 
    if (isEmpty(root)) {
        printf("stack is empty\n");
    }
    int number = atoi(root->data);
    printf("print:%d\n",number);
} 



