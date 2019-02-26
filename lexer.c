#include "lexer.h"
#include "global.h"
#include "tokenLinkedList.h"


/*  use the buffer which is a single line from the input
    and seperate the keywords into tokens
*/
void lexerAnalysis(){
    int i = 0; 
    head = NULL;
    tmp = NULL;
    printf("----print from lexer-----\n");
    int index = 0;
    char data[255];
    while(buffer[index] != '\0'){
        
        if(buffer[index]!=' '){
            lexerAppendCh(data,buffer[index]);
        }else if(buffer[index] == ' '){                // in here we omit the space
            /* add this data to token
                data->data
                isNUM-> FALSE
                int->null
            */
            if(i==0){
                printf("%s\n",data);
                head = prepend(head,0,FALSE,data);
                data[0] = '\0';
                // memset(data,0,255);
                i++;
            }else{
                printf("%s\n",data);
                head = append(head,0,FALSE,data);
                data[0] = '\0';
                // memset(data,0,255);
            }
            //clear the char in data array
        }else
        {
            printf("extra else here");
        }
        
        index++;
    }
    // add this data below to token as well 
    printf("%s\n",data);
    // printf("%s\n",buffer);
}

void lexerAppendCh(char* s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}