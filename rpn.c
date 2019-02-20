#include "rpn.h"
#include "global.h"
// #include "util.h"
#include "stack.h"
#include "tokenTable.h"


#include "printer.h"   //only for test use        *delete later*



void toPostfix(){
    globalStack = NULL;         //create the stack
    int c = 0;                 //counter for looping the line string
    _bool checker = FALSE; //check if the next character is the number
    int preCh;
    head = NULL;
    tmp = NULL;

    while(line[c]!= '\0'){
        int ch = line[c]; //for simple codeing
        if(c>0) preCh = line[c-1];
        if(((ch<=57)&&(ch>=48))&&((preCh<=57)&&(preCh>=48))){
            checker = TRUE;
        }
        
        if(checker){
            printf("check is true and %c is added to token table\n",ch);
            int num = ch - '0';

            checker = FALSE;
        }else if(ch<48 || ch>57 ){
            if(ch == 41){
                printf("This ) symbol is found and deleted\n");
                int popOut = (int)pop(&globalStack);
                char popP = pop(&globalStack);
                printf("previous %c is poped\n",popP);
                
                head = append(head,popOut,FALSE);
                
            }else{
                push(&globalStack,ch);
            }
        }else{
            printf("number %c is added to token table\n",ch);
            // output[counter] = ch;
            int num = ch - '0';
            head = append(head,num,TRUE);

        }
        // printf("%c\n",line[c]);
        c++;

    }
    printf("error!0\n");
    callback disp = display;
    traverse(head,disp);

    traverseList(head);
    printf("error!1\n");

}