#include "service.h"
#include "global.h"
#include "stack.h"
#include "tokenLinkedList.h"
#include "util.h"
#include "lexer.h"
#include "scanner.h"


void pushService(char data[]){
    int len;
    len = strlen(data);
    if(data[len-1] == '\n') data[len-1] = 0;
    pushNum(&globalStack,data);
}

void rvalue(char data[]){
    int num;
    if(search(head,data) == FALSE){
        num = findVar(head,data);
        printf("rvalue is :%d -- rvalue()\n",num);
        pushRvalue(&globalStack,data,num);
    }

}

void lvalue(char data[]){
    /* create a new token added to linked list then push */
    if(search(head,data)){
        if(head == NULL){
        head = prependAddress(head,data);
    }else{
        head = appendAddress(head,data);
    }
    }
    if(search(head,data) == FALSE){
        pushLvalue(&globalStack,data);
    }
    traverseList(head);
}  

void popService(){
    popStack(&globalStack);
};

void noooice(){
    int val = popStack(&globalStack);
    printf("val: %d   -- noooice()\n",val);
    char* varName = (char*)popVarName(&globalStack);
    printf("varName: %s   -- noooice()\n",varName);
    updateVar(head,varName,val);
    traverseList(head);
}

void copy(){
}

void halt(){
    printf("halt!\n");
    exit(0);
}

void add(){}

void minus(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result = second - first;
    printf("result of %d - %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//*
void multi(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result = second * first;
    printf("result of %d * %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
// /
void divi(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result = second / first;
    printf("result of %d / %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}

void remainderCal(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result = second % first;
    printf("result of %d div %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//&
void andGate(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result = first & second;
    printf("result of %d & %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//!
void negates(){
    int first = popStack(&globalStack);
    int result = !first;
    printf("result of negates:%d\n",result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
// |
void orGate(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result = first | second;
    printf("result of %d | %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
    
//<>
void equalCheck(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result;
    if(first == second){
        result = 0;
    }else
    {
        result = 1;
    }
    printf("result of %d <> %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//<=
void lessEqual(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result;
    if(second <= first){
        result = 1;
    }else
    {
        result = 0;
    }
    printf("result of %d <= %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//>=
void greaterEqual(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result;
    if(second >= first){
        result = 1;
    }else
    {
        result = 0;
    }
    printf("result of %d >= %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//<
void less(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result;
    if(second < first){
        result = 1;
    }else
    {
        result = 0;
    }
    printf("result of %d <= %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//>
void greater(){
    int first = popStack(&globalStack);
    int second = popStack(&globalStack);
    int result;
    if(second > first){
        result = 1;
    }else
    {
        result = 0;
    }
    printf("result of %d <= %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}

void print(){
    peek(globalStack);
}

//=
void equalSign(){}


void gotoLoop(char label[]){  //data[] here is the label name 
    gotoFunc(label);
}
void gotoFalse(char label[]){
    int check = popStack(&globalStack);
    printf("check:%d\n",check);
    if(check == 0){
        gotoFunc(label);
    }
}

void parse(char ins[],char data[]){
    if(strcmp(ins,"push") == 0){pushService(data);}
    if(strcmp(ins,"rvalue") == 0){rvalue(data);}
    if(strcmp(ins,"lvalue") == 0){
        lvalue(data);
    }
    if(strcmp(ins,"print") == 0){print();}
    if(strcmp(ins,"pop") == 0){popService();}
    if(strcmp(ins,":=") == 0){noooice();}
    if(strcmp(ins,"copy") == 0){copy();}
    if(strcmp(ins,"halt") == 0){halt();}
    if(strcmp(ins,"&") == 0){andGate();}
    if(strcmp(ins,"|") == 0){orGate();}
    if(strcmp(ins,"div") == 0){remainderCal();}
    if(strcmp(ins,"+") == 0){add();}
    if(strcmp(ins,"-") == 0){minus();}
    if(strcmp(ins,"*") == 0){multi();}
    if(strcmp(ins,"/") == 0){divi();}
    if(strcmp(ins,"!") == 0){negates();}
    if(strcmp(ins,"<>") == 0){equalCheck();}
    if(strcmp(ins,"<=") == 0){lessEqual();}
    if(strcmp(ins,">=") == 0){greaterEqual();}
    if(strcmp(ins,">") == 0){greater();}
    if(strcmp(ins,"<") == 0){less();}
    if(strcmp(ins,"=") == 0){equalSign();}
    if(strcmp(ins,"goto") == 0){gotoLoop(data);}
    if(strcmp(ins,"gofalse") == 0){gotoFalse(data);}
}