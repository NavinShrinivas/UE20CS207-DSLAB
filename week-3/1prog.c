#include "1_1.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct head* top = (struct head*)malloc(sizeof(struct head));
    top->link=NULL;//init struct
    top->num = 0;
    while(true)
    {
        printf("1.Enter details\n");
        printf("2.Display details\n");
        printf("Anything else for exit.\n");
        printf("Choice : ");
        int choice;
        scanf("%d",&choice);
        if(choice == 1)
        {
            enterdetails(top);
        }
        else if(choice == 2)
        {
            display(top);
        }
    }
}
