#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


typedef struct token {
    char chr[255];
    _bool isNum;
    int value;
    struct token * next;
} token;

token* head;
token* tmp;
typedef void (*callback)(token* data);


typedef void (*callback)(token* data);
token* create(int value,_bool isNum, token* next,char chr[]);
token* prepend(token* head,int value, _bool isNum,char chr[]);
token* append(token* head,int value,_bool isNum,char chr[]);
void traverse(token* head,callback f);
void display(token* n);
void dispose(token* head);
int count(token *head);
token* remove_back(token* head);
void traverseList(token *head);
token* replaceNewToken(token* head,int value,_bool isNum,char chr[]);
token* reverse(token* head);