// C program for linked list implementation of stack 
#include "stack.h"
#include "tokenLinkedList.h"
#include "util.h"


// A structure to represent a stack 
struct StackNode 
{   
    int num;
    _bool isVar;
    _bool isNum;
    char variableName[255];
    struct StackNode* next; 
}; 

struct StackNode* newNode(char variableName[]) 
{ 
    int len;
    len = strlen(variableName);
    if(variableName[len-1] == '\n') variableName[len-1] = 0;
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode)); 
    strcpy(stackNode->variableName,variableName);
    stackNode->next = NULL; 
    return stackNode; 
} 


struct StackNode* newVariableNode(char variableName[]) 
{ 
    int len;
    len = strlen(variableName);
    if(variableName[len-1] == '\n') variableName[len-1] = 0;
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode)); 
    strcpy(stackNode->variableName,variableName);
    stackNode->next = NULL;
    return stackNode; 
} 

    
void pushLvalue(struct StackNode** root,char variableName[]) 
{   
    struct StackNode* stackNode = newVariableNode(variableName);
    stackNode->isVar = TRUE;
    stackNode->isNum = FALSE;
    stackNode->next = *root;
    *root = stackNode;
    printf("variableName of %s is pushed -- pushLvalue()\n",stackNode->variableName);
} 

void pushRvalue(struct StackNode** root, char variableName[],int num) 
{   
    struct StackNode* stackNode = newVariableNode(variableName);
    stackNode->isVar = TRUE;
    stackNode->isNum = FALSE;
    stackNode->num = num;
    stackNode->next = *root; 
    *root = stackNode; 
    printf("content:%d of %s pushed to stack\n",stackNode->num, variableName); 
} 

int isEmpty(struct StackNode *root) 
{ 
    return !root; 
} 

void pushNum(struct StackNode** root, char variableName[]) 
{   
    struct StackNode* stackNode = newNode(variableName);
    int number = atoi(stackNode->variableName); 
    stackNode->isVar = FALSE;
    stackNode->isNum = TRUE;
    stackNode->num = number;
    stackNode->next = *root; 
    *root = stackNode; 
    printf("%s pushed to stack\n", variableName); 
} 


int popStack(struct StackNode** root) 
{ 
    if (isEmpty(*root)) {
        printf("Empty stack! the number returned is 0\n");
    }
    struct StackNode* temp = *root; 
    *root = (*root)->next;
    int number;
    int tempNum;
    
    if(temp->isVar){
        tempNum = findVar(head,temp->variableName);
        printf("tempNum:%d -- popStack()\n",tempNum);
        number = tempNum;
        printf("content: %d of variable: %s is popped -- popStack()\n",temp->num,temp->variableName);
    }else if(temp->isNum){
        number = atoi(temp->variableName);  
        printf("pop:%d\n",number);
    }
    free(temp); 
    return number; 
} 

char* popVarName(struct StackNode** root) 
{ 
    if (isEmpty(*root)) {
        printf("Empty stack! the number returned is 0\n");
    }
    struct StackNode* temp = *root; 
    *root = (*root)->next;
    char* varName;
    
    varName = temp->variableName;
    free(temp); 
    return varName; 
} 

int popNum(struct StackNode** root){ //associate with operators
    if (isEmpty(*root)) {
        printf("Empty stack! the number returned is 0\n");
    }
    struct StackNode* temp = *root; 
    *root = (*root)->next;
    int number;
    if(strcmp(temp->variableName,"address" ) != 0){
        number = atoi(temp->variableName);  
        printf("pop:%d\n",number);
    }
    free(temp); 
    return number; 
}

// char* popAddress(struct StackNode** root){   //associate with := instrcution
//     if (isEmpty(*root)) {
//         printf("Empty stack! the number returned is 0\n");
//     }
//     struct StackNode* temp = *root; 
//     *root = (*root)->next;
//     int number;
//     char *address;
//     if(strcmp(temp->variableName,"address") != 0){
//         number = atoi(temp->variableName);  
//         printf("pop:%d\n",number);
//     }
//     free(temp); 
//     return address; 
// }

void peek(struct StackNode* root) 
{ 
    if (isEmpty(root)) {
        printf("stack is empty\n");
    }
    int number = atoi(root->variableName);
    printf("print:%d\n",number);
} 


