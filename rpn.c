#include "rpn.h"
#include "global.h"
#include "stack.h"
#include "tokenLinkedList.h"

#include "printer.h"   //only for test use        *delete later*



void toPostfix(){
    globalStack = NULL;         //create the stack
    int c = 0, counter = 0;                 //counter for looping the line string
    _bool checker = FALSE; //check if the next character is the number
    int preCh;
    char data[] = "\0";
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
            head = replaceNewToken(head,num,TRUE,data);
            /*place to put in parse tree */

            /*  -------------------------   */
            checker = FALSE;
        }else if(ch<48 || ch>57 ){
            if(ch == 41){
                printf("This ) symbol is found and deleted\n");
                int popOut = (int)pop(&globalStack);
                char popP = pop(&globalStack);
                printf("previous %c is poped\n",popP);
                head = append(head,popOut,FALSE,data);
                /*place to put in parse tree */

                /*  -------------------------   */
            }else{
                push(&globalStack,ch);
            }
        }else{
            if(counter == 0){
                printf("number %c is added to token table\n",ch);
                // output[counter] = ch;
                int num = ch - '0';
                head = prepend(head,num,TRUE,data);
                /*place to put in parse tree */

                /*  -------------------------   */
                counter++;
            }else{
                printf("number %c is added to token table\n",ch);
                // output[counter] = ch;
                int num = ch - '0';
                head = append(head,num,TRUE,data);
                /*place to put in parse tree */

                /*  -------------------------   */
            }
            

        }
        // printf("%c\n",line[c]);
        c++;

    }



    traverseList(head);
    callback disp = display;
    traverse(head,disp);
    printf("\n");


}