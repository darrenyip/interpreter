#include "scanner.h"



void runFile(char* path){
    /* create the global stack */
    globalStack = NULL;
    int counter = 0;

    /* open file  */ 
    FILE *fptr;     
    char ch;
    fptr = fopen(path,"r");
    if(fptr == NULL){
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr);
    while(ch != EOF){
        if(ch<48 || ch>57){
            if(ch == 41){
                printf("This ( symbol is found and poped\n");
                int popOut = (int)pop(&globalStack);
                char popP = pop(&globalStack);
                printf("previous %c is poped\n",popP);
                output[counter] = popOut;
                counter++;
            }else
            {
                push(&globalStack,ch);
            }
            
        }else
        {   
            printf("number %c is added to output array\n",ch);
            output[counter] = ch;
            counter++;
        }
        ch = fgetc(fptr);
    }
    printf("close file\n");
    fclose(fptr);
    //test ouput
    printOutput(output);

}
void runPrompt(){
    char str[80];
    bool infLoop = 1;
    while(infLoop){
        printf("> ");
        scanf("%79s",str);
        printf("%s\n",str);
    }

}