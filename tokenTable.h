#include <stdio.h>
#include <stdlib.h>
#include "util.h"


typedef struct token {
    _bool isNum;
    int value;
    struct token * next;
} token;

typedef void (*callback)(token* data);
token* create(int value,_bool isNum, token* next);
token* prepend(token* head,int value, _bool isNum);
token* append(token* head,int value,_bool isNum);
void traverse(token* head,callback f);
void display(token* n);
void dispose(token* head);
int count(token *head);