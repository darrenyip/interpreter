#include "scanner.h"
#include "global.h"


char* appendCh(char *cArr,char c){
    unsigned len = strlen(cArr);
    cArr[len+1] = cArr[len];
    cArr[len] = c;
    return cArr;
}

void readFile(char* path){
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
    /* --------------------------------- */

    ch = fgetc(fptr);
    while(ch != EOF){
        appendCh(cArr,ch);   //append the new ch to the end of line
        cArr++;
        ch = fgetc(fptr);
    }
    printf("Read from text file successful!!\n");
    printf("Output line = %s\n",line); // print the line from global ---> line    
    printf("Close file\n");
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