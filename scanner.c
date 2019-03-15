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
    strcpy(filePath,path);
    head = NULL;
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
        // printf("%s\n",buffer);
    }

    fclose(fptr);
    printf("-----------------------------------------\n");
}

void gotoFunc(char label[]){
    FILE *fptr;     
    char ch;
    char* cArr; // pointer to global --->  line
    cArr = line;
    
    fptr = fopen(filePath,"r");
    /* ----error when file cannot be opened ----  */
    if(fptr == NULL){
        printf("Cannot open file \n");
        exit(0);
    }
    _bool gotoFound = FALSE;
    _bool startCheck = TRUE;
    while(fgets(buffer,255,(FILE*) fptr)){
        if(startCheck){
            gotoFound = lexerCheck(label);//this function is at lexer.c and return boolean value
            if(gotoFound){
                startCheck = FALSE;
            }
        }
        if(gotoFound){
            lexerAnalysis();
        }
        // printf("%s\n",buffer);
    }

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