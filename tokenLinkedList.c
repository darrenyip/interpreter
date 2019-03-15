#include "tokenLinkedList.h"
#include "stack.h"
#include "global.h"
/*
    a token table which can store all the input token
    and which can be put into tree later on
*/



/*
    create a new token
    initialize the value and next token
    return the newly created token
*/
token* create(int value, token* next,char chr[]){
    token* new_token = (token*)malloc(sizeof(token));
    if(new_token == NULL){
        printf("Error creating a new node.\n");
        exit(0);
    }
    strcpy(new_token->chr,chr);
    new_token->value = value;
    new_token->next = next;

    return new_token;
}
token* createNew(token* next,char chr[]){
    token* new_token = (token*)malloc(sizeof(token));
    if(new_token == NULL){
        printf("Error creating a new node.\n");
        exit(0);
    }
    strcpy(new_token->chr,chr);

    new_token->next = next;

    return new_token;
}



/*
    add a new token at the begining of the list
*/
// token* prepend(token* head,int value, _bool isNum,char chr[]){
//     token* new_token = create(value,isNum,head,chr);
//     head = new_token;
//     return head;
// }
token* prepend(token* head,char chr[]){
    token* new_token = createNew(head,chr);
    head = new_token;
    return head;
}


token* prependAddress(token* head,char chr[]){
    token* new_token = createNew(head,chr);
    head = new_token;
    pushLvalue(&globalStack,chr); 
    return head;
}



/*
    add a new token at the end of the list
*/
// token* append(token* head,int value,_bool isNum,char chr[]){
//     if(head == NULL)
//         return NULL;
//     /* go to the last node */
//     token *cursor = head;
//     while(cursor->next != NULL)
//         cursor = cursor->next;

//     /* create a new node */
//     token* new_token =  create(value,isNum,NULL,chr);
//     cursor->next = new_token;

//     return head;
// }
token* append(token* head,char chr[]){
    if(head == NULL)
        return NULL;
    /* go to the last node */
    token *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;

    /* create a new node */
    token* new_token =  createNew(NULL,chr);
    cursor->next = new_token;

    return head;
}

token* appendAddress(token* head,char chr[]){
    
    
    if(head == NULL)
        return NULL;
    /* go to the last node */
    token *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;

    /* create a new node */
    token* new_token =  createNew(NULL,chr);
    cursor->next = new_token;
    
    pushLvalue(&globalStack,chr); //push address into stack
    return head;
}

/*
    traverse the linked list
*/
void traverse(token* head,callback f){
    token* cursor = head;
    if(cursor == NULL){
        printf("list is empty!!!!\n");
    }
    while(cursor != NULL){
        f(cursor);
        cursor = cursor->next;
    }
}
/*
    traverse the list
*/
void traverseList(token *head){
    struct token *temp;
    if(head == NULL){
        printf("this shit is empty\n");
        return;
    }
    temp = head;
    while(temp!=NULL){
        printf("Variable token{\n");
        printf("variable : %s ",temp->chr);
        printf("= %d\n",temp->value);
        printf("}\n");
        temp = temp->next;
    }
}

// display
void display(token* n){
    if(n!=NULL){
        // if(n->isNum==1){
        //     printf("%d ",n->value);
        // }else{
        //     printf("%c ",n->value);
        // }
        printf("%c ",n->value);
    }
}
/*
    remove all element of the list
*/
void dispose(token* head){
    token *cursor, *tmp;

    if(head!=NULL){
        cursor = head->next;
        head->next = NULL;
        while(cursor != NULL){
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
}
int count(token *head){
    token *cursor = head;
    int c= 0;
    while(cursor != NULL){
        c++;
        cursor = cursor->next;
    }
    return c;
}

token* remove_back(token* head){
    if(head == NULL){
        return NULL;
    }
    token *cursor = head;
    token *back = NULL;
    while(cursor->next != NULL){
        back = cursor;
        cursor = cursor->next;
    }
    if(back != NULL){
        back->next = NULL;
    }
    if(cursor == head){
        head = NULL;
    }
    free(cursor);
    return head;
}

token* replaceNewToken(token* head,int value, char chr[]){
    if(head ==  NULL){
        return NULL;
    }
    token *cursor = head;
    int valueInToken;
    while(cursor != NULL){
        valueInToken = cursor->value;
        if(cursor->next == NULL){
            cursor->value = valueInToken *10 + value;
            printf("new value replaced! = %d\n",cursor->value);
        }
        cursor = cursor->next;
    }
    return head;
}

token* reverse(token* head){
    token* prev = NULL;
    token* current = head;
    token* next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

_bool search(token* head,char chr[])
{
    _bool check = TRUE;
    token *cursor = head;
    while(cursor!=NULL)
    {
        if(strcmp(cursor->chr,chr)==0){
            printf("%s exist.",chr );
            check = FALSE;
        }
        cursor = cursor->next;
    }
    return check;
}

token* addAddressToLinkedList(token* head,char chr[]){
    if(head == NULL){
        printf("prepend here\n");
        head = prependAddress(head,chr);
    }else 
    {
        printf("append here\n");
        head = appendAddress(head,chr);
    }
    
    return head;
}

int findVar(token* head,char data[]){
    token *cursor = head;
    int val;
    while(cursor!=NULL){
        if(strcmp(cursor->chr,data)==0){
            val = cursor->value;
        }
        cursor = cursor->next;
    }
    
    return val;
}

void updateVar(token* head,char data[],int num){
    token *cursor = head;
    while(cursor!=NULL){
        if(strcmp(cursor->chr,data)==0){
            cursor->value = num;
        }
        cursor = cursor->next;
    }
}