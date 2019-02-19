#include "rpn.h"
#include "global.h"
#include "util.h"
#include "stack.h"


#include "printer.h"   //only for test use        *delete later*



void toPostfix(){
    globalStack = NULL;         //create the stack
    int c = 0,counter = 0;                  //counter for looping the line string
    _bool checker = FALSE; //check if the next character is the number
    int preCh;
    int* ptr;
    ptr = output;
    while(line[c]!= '\0'){
        int ch = line[c]; //for simple codeing
        if(c>0) preCh = line[c-1];
        if(((ch<=57)&&(ch>=48))&&((preCh<=57)&&(preCh>=48))){
            checker = TRUE;
        }
        if(checker){
            printf("check is true and %c is added to ouput\n",ch);
            --ptr;
            *ptr = (int)(*ptr)*10 + ch;
            ++ptr;
            checker = FALSE;
        }else if(ch<48 || ch>57 ){
            if(ch == 41){
                printf("This ( symbol is found and poped\n");
                int popOut = (int)pop(&globalStack);
                char popP = pop(&globalStack);
                printf("previous %c is poped\n",popP);
                *ptr = popOut;
                ++ptr;
                counter++;
            }else{
            push(&globalStack,ch);
            }
        }else{
            printf("number %c is added to output array\n",ch);
            // output[counter] = ch;
            *ptr = ch;
            ++ptr;
            counter++;
        }
        // printf("%c\n",line[c]);
        c++;
        
    }
    printOutput(output);

}