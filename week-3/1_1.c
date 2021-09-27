#include <stdio.h>
#include <stdlib.h>
#include "1_1.h"

void enterdetails(struct head* top)
{
    if(top->link==NULL)
    {
        struct details* temp=(struct details*)malloc(sizeof(struct details));
        temp->llink=NULL;
        temp->rlink=NULL;
        top->link=temp;
        printf("Enter Details : \n");
        printf("Name : ");
        scanf("\t%[^\n]*c",temp->name);
        printf("Phone number : ");
        scanf("%i",temp->number);
        printf("Enter address : ");
        scanf("\t%[^\n]%*c",temp->address);
        top->num=top->num+1;
        return;


    }
    struct details* curr=top->link;
    while(curr->rlink!=NULL){
        curr=curr->rlink;
    }
    struct details* temp = (struct details*)malloc(sizeof(struct details));
    temp->llink=curr;
    curr->rlink=temp;
    temp->llink=NULL;//the details are always being added to the end of the linked list
    printf("Enter Details : \n");
    printf("Name : ");
    scanf("%s",temp->name);
    printf("Phone number : ");
    scanf("%d",temp->number);
    printf("Enter address : ");
    scanf("\t%[^\n]%*c",temp->address);
    top->num=top->num+1;
    return;
}

void display(struct head* top)
{
    if(top->link==NULL)
    {
        printf("Contats register is empty!\n");
        return;
    }
    struct details* curr = top->link;
    int i=1;
    while(curr!=NULL)
    {
        printf("Details of person %d ",i);
        i+=1;
        printf("Name : %s",curr->name);
        printf("Phone number : %lu",curr->number);
        printf("Address : %d",curr->address);
        curr=curr->rlink;
    }

}
