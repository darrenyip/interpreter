
#include <stdio.h>

void printOutput(int arr[]){
    // for(int i; i<20;i++){
    //     printf("works2?\n");
    //     printf("%c",arr[i]);
    // }
    int i,*ptr;
    ptr = arr;
    printf("Printer output = ");
    for(int i =0;i<20;i++){
        printf("%c",*ptr);
      /* move to the next location */
        ptr++;
    }
    printf("\n");
    printf("50 = %c\n",50);
}