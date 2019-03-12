#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "scanner.h"
#include "printer.h"
#include "tokenLinkedList.h"


int main(int argc, char *argv[])
{   
    globalStack = NULL;
    head = NULL;
    /* scanner module first */
    if(argc > 2 ){
        printf("Usage: AMI [script]");
        exit(1);
    }else if(argc == 2){
        printf("-----------------------------------------\n");
        printf("runFile launched\n");
        readFileByLineAndExecute(argv[1]);
    }else {
        printf("runPromt launched\n");
        runPrompt();
    }


    return 0;
}
