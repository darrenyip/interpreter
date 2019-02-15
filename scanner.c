#include "scanner.h"



void runFile(char* path){
    /* create the global stack */
    globalStack = NULL;
    push(&globalStack,'d');
    push(&globalStack,'<');
    char c = pop(&globalStack);
    printf("%c poped\n",c);
    c = pop(&globalStack);
    printf("%c poped\n",c);
    c = pop(&globalStack);
    printf("%c poped\n",c);


    FILE *fptr;     //open file 
    char ch;
    fptr = fopen(path,"r");
    if(fptr == NULL){
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr);
    while(ch != EOF){
        push(&globalStack,ch);
        ch = fgetc(fptr);
    }
    printf("close file");
    fclose(fptr);

}
void runPrompt(){

}