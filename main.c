#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"


int main(int argc, char *argv[])
{   
    /* scanner module first */
    if(argc > 2 ){
        printf("Usage: AMI [script]");
        exit(1);
    }else if(argc == 2){
        printf("runFile launched\n");
        runFile(argv[1]);
    }else {
        printf("runPromt launched\n");
        runPrompt();
    }


    return 0;
}
