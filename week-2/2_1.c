#include"2_1.h"
#include <stdio.h>
#include <stdlib.h>

void inputquad(struct polytop* quad)
{
    printf("Enter number of terms in the quadratic : ");
    int n;
    scanf("%d",&n);
    if(n==0)
    {
        quad->link=NULL;
        //yeah i actually have to do dis for stupid inputs as 
        //"All edge cases must be handled" crap
        return;
    }
    struct poly* temp=(struct poly*)malloc(sizeof(struct poly));
    printf("Polynomial : 1\n");
    printf("Enter Coefficient : ");
    scanf("%d",&(temp->coeff));
    printf("Enter power of X : ");
    scanf("%d",&(temp->px));
    printf("Enter power of Y : ");
    scanf("%d",&(temp->py));
    quad->link=temp;//the first node to be appending to

    struct poly* copy=quad->link;
    for(int i=1;i<n;i++)
    {
        struct poly* temp=(struct poly*)malloc(sizeof(struct poly));
        printf("Polynomial : %d\n",i+1);
        printf("Enter Coefficient : ");
        scanf("%d",&(temp->coeff));
        printf("Enter power of X : ");
        scanf("%d",&(temp->px));
        printf("Enter power of Y : ");
        scanf("%d",&(temp->py));
        copy->link=temp;
        copy=copy->link;
    }
    return;
}
void displayquad(struct polytop* quad)
{
    struct poly* curr = quad->link;
    if(quad->link == NULL)
    {
        printf("\nNo polynomials in the quad\n");
        return;
    }
    while(curr->link!=NULL)
    {
        printf("%dX^%dY^%d+",curr->coeff , curr->px , curr->py);
        curr=curr->link;
    }
    printf("%dX^%dY^%d",curr->coeff , curr->px , curr->py);
    
}
void addquads(struct polytop* quad1 , struct polytop* quad2)
{
    //adding quad2 onto quad1
    struct poly* curr = quad1->link;
    while(curr!=NULL)
    {
        struct poly* adder = quad2->link;
        while(adder!=NULL)
        {
            if(adder->px == curr->px && adder->py == curr->py)
            {
                curr->coeff=curr->coeff+adder->coeff;
            }
            adder=adder->link;
        }
        curr=curr->link;
    }
    curr=quad1->link;
    while(curr->link!=NULL)
        curr=curr->link;
    struct poly* temp = quad2->link;
    while(temp!=NULL)
    {
        int existflag=0;
        struct poly* temp2=quad1->link;
        while(temp2!=NULL)
        {
            if(temp2->px == temp->px && temp2->py==temp->py && existflag==0)
            {
                existflag=1;
                break;
            }
            temp2=temp2->link;
        }
        if(existflag)
            temp=temp->link;
        else{
            struct poly* newpoly=(struct poly*)malloc(sizeof(struct poly));
            newpoly->link=NULL;
            newpoly->px=temp->px;
            newpoly->py=temp->py;
            newpoly->coeff=temp->coeff;
            curr->link=newpoly;
            curr=curr->link;
            temp=temp->link;
        }
    }

}
