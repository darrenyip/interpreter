#include "util.h"
#include <stdio.h>

struct StackNode* globalStack;
int output[50];
char line[60]; //  a single line of input 
typedef struct token {
    _bool isNum;
    int value;
    struct token * next;
}token_t;
struct token table[20];