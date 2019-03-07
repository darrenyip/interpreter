#include "service.h"
#include "global.h"
#include "stack.h"
// #include "stack.h"


void pushService(char data[]){
    int len;
    len = strlen(data);
    if(data[len-1] == '\n') data[len-1] = 0;
    pushNum(&globalStack,data);
}

void rvalue(char data[]){
    pushRvalue(&globalStack,data);
}

void lvalue(){}

void popService(){
    popNum(&globalStack);
};

void noooice(){}

void copy(){}

void halt(){
    printf("halt!\n");
    exit(0);
}

void add(){}

void minus(){
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
    int result = second - first;
    printf("result of %d - %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//*
void multi(){}
// /
void divi(){
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
    int result = second / first;
    printf("result of %d / %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}

void remainderCal(){
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
    int result = second % first;
    printf("result of %d div %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//&
void andGate(){
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
    int result = first & second;
    printf("result of %d & %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
//!
void negates(){
    int first = popNum(&globalStack);
    int result = !first;
    printf("result of negates:%d\n",result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
// |
void orGate(){
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
    int result = first | second;
    printf("result of %d | %d = %d\n",second,first,result);
    char data[20];
    sprintf(data,"%d",result);
    pushNum(&globalStack,data);
}
    
//<>
void equalCheck(){
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
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
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
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
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
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
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
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
    int first = popNum(&globalStack);
    int second = popNum(&globalStack);
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

void parse(char ins[],char data[]){
    if(strcmp(ins,"push") == 0){pushService(data);}
    if(strcmp(ins,"rvalue") == 0){rvalue(data);}
    if(strcmp(ins,"lvalue") == 0){lvalue();}
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
}