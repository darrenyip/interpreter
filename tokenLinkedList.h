#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


typedef struct token {
    char chr[255];
    int value;
    struct token * next;
} token;

token* head;
token* tmp;
typedef void (*callback)(token* data);


typedef void (*callback)(token* data);
token* create(int value, token* next,char chr[]);


token* prepend(token* head,char chr[]);
token* append(token* head,char chr[]);


token* prependAddress(token* head,char chr[]);
token* appendAddress(token* head,char chr[]);
token* addAddressToLinkedList(token* head,char chr[]);

void traverse(token* head,callback f);
void display(token* n);
void dispose(token* head);
int count(token *head);
token* remove_back(token* head);
void traverseList(token *head);
token* replaceNewToken(token* head,int value,char chr[]);
token* reverse(token* head);

int search(token* head,char data[]);

int findVar(token* head,char data[]);

void updateVar(token* head,char data[], int num);