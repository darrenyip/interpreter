#include <assert.h>

typedef char *string;
string String(char *);
typedef char _bool; // instead of bool, I used _bool prevent error
#define TRUE 1
#define FALSE 0

void *checked_malloc(int);
// void *checked_malloc(int len){
//     void *p = malloc(len);
//     assert(p);
//     return p;
// }