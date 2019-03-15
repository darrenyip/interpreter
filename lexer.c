#include "lexer.h"
#include "global.h"
#include "service.h"
#include "util.h"


/*  use the buffer which is a single line from the input
    and seperate the keywords into tokens
*/
void lexerAnalysis(){
    int i = 0,j = 0; 
    printf("--------print from lexer--------\n");
    int index = 0;
    char instructions[10];
    char data[255];

    while(buffer[index] != '\0'){
        if(buffer[index]!=' ' && i == 0){
            lexerAppendCh(instructions,buffer[index]);
        }else if((buffer[index] ==' ' && (i == 0))){
            // printf("do nothing cuz a space found\n");
            if(buffer[index+1] != ' '){
                i++;
            }
            
        }else
        {
            lexerAppendCh(data,buffer[index]);
        }
        index++;
    }
    int lenIns,lenData;
    lenIns = strlen(instructions);
    lenData = strlen(data);
    if(instructions[lenIns-1] == '\n') instructions[lenIns-1] = 0;
    if(data[lenData-1] == '\n') data[lenData - 1] = 0;
    printf("instructions=%s   ",instructions);
    printf("data=%s\n",data);
    parse(instructions,data);
    memset(instructions,0,10);
    memset(data,0,255);
    // add this data below to token as well 
    printf("\n\n");
}

int lexerCheck(char label[]){
    int i = 0,j = 0; 
    // printf("$$$$$$$$$$$$$ lexer check begin$$$$$$$$$\n");
    int index = 0;
    char instructions[10];
    char data[255];

    int labelFound = 0;

    while(buffer[index] != '\0'){
        if(buffer[index]!=' ' && i == 0){
            lexerAppendCh(instructions,buffer[index]);
        }else if((buffer[index] ==' ' && (i == 0))){
            // printf("do nothing cuz a space found\n");
            if(buffer[index+1] != ' '){
                i++;
            }
            
        }else
        {
            lexerAppendCh(data,buffer[index]);
        }
        index++;
    }
    int lenIns,lenData;
    lenIns = strlen(instructions);
    lenData = strlen(data);
    if(instructions[lenIns-1] == '\n') instructions[lenIns-1] = 0;
    if(data[lenData-1] == '\n') data[lenData - 1] = 0;
    // printf("instructions=%s   ",instructions);
    // printf("data=%s\n",data);
    if((strcmp(instructions,"label") == 0)&&(strcmp(data,label)==0)){
        labelFound = 1;
        printf("+++++++++++++++label is found! :%s\n",data);
    }
    memset(instructions,0,10);
    memset(data,0,255);
    // add this data below to token as well 
    // printf("\n");
    return labelFound;
} 

void lexerAppendCh(char* s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}