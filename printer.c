#include "printer.h"
#include "global.h"


void printOutput(){
    struct token *ptr = NULL;
    ptr = table;
    // while(ptr!=NULL){
    //     if(ptr->isNum){
    //         printf("value: %d ", ptr->value);
    //     }else
    //     {
    //         printf("newValue: %c ",ptr->value);
    //     }
        
    //     ++ptr;
    // }
    for(int i =0;i<10;i++){
        if(ptr->isNum){
            printf("%d ",ptr->value);
        }else
        {
            printf("%c ",ptr->value);
        }
        ++ptr;
    }
    printf("\n");
}