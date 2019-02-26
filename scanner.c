#include "scanner.h"
#include "global.h"
#include "lexer.h"
#include "tokenLinkedList.h"


char* appendCh(char *cArr,char c){
    unsigned len = strlen(cArr);
    cArr[len+1] = cArr[len];
    cArr[len] = c;
    return cArr;
}


void readFileByLineAndExecute(char* path){
    FILE *fptr;     
    char ch;
    char* cArr; // pointer to global --->  line
    cArr = line;
    fptr = fopen(path,"r");
    /* ----error when file cannot be opened ----  */
    if(fptr == NULL){
        printf("Cannot open file \n");
        exit(0);
    }
    while(fgets(buffer,255,(FILE*) fptr)){
        //implement this
        lexerAnalysis();
        traverseList(head);
        // printf("%s\n",buffer);
    }
    traverseList(head);

    fclose(fptr);
    printf("-----------------------------------------\n");
}


/* -----use terminal to take input from user------ */
void runPrompt(){
    char str[80];
    bool infLoop = 1;
    while(infLoop){
        printf("> ");
        scanf("%79s",str);
        printf("%s\n",str);
    }
}
/* ------------------------------------------ */