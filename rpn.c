#include "rpn.h"
#include "global.h"
#include "util.h"
#include "stack.h"


#include "printer.h"   //only for test use        *delete later*



void toPostfix(){
    globalStack = NULL;         //create the stack
    int c = 0,counter = 0;                  //counter for looping the line string
    _bool checker = FALSE; //check if the next character is the number
    int preCh = line[0];
    int curCh;
    while(line[c]!= '\0'){
        int ch = line[c]; //for simple codeing
        if(checker){
            output[counter] = output[counter]*10 + ch;
        }else if(ch<48 || ch>57 ){
            if(ch == 41){
                printf("This ( symbol is found and poped\n");
                int popOut = (int)pop(&globalStack);
                char popP = pop(&globalStack);
                printf("previous %c is poped\n",popP);
                output[counter] = popOut;
                counter++;
            }else{
            push(&globalStack,ch);
            }
        }else{
            printf("number %c is added to output array\n",ch);
            output[counter] = ch;
            counter++;
        }
        // printf("%c\n",line[c]);
        c++;
        curCh = line[c];
        if(((curCh<=57)&&(curCh>=48))&&((preCh<=57)&&(preCh>=48))){
            checker = TRUE;
        }
    }
    printf("here\n");
    printOutput(output);
    printf("here2\n");

}