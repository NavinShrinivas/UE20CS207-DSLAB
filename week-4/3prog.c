#include "3_1.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    char input[100];
    printf("Enter a string : ");
    scanf("\t%[^\n]%*c",input);
    for(int i=0;i<strlen(input);i++)
    {
        if(i==0)
            pushe(st,input[i]);
        else{
            if(peekstack(st)!=input[i])
                pushe(st,input[i]);
            else
                continue;
        }
    }
    printf("The string without repeated letters :");
    displaystack(st);
   
}
