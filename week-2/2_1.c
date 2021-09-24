#include"2_1.h"

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
    quad->link=temp;

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
    copy->link=NULL;//yeah i know this is seems very mess :'( , maybe
    //an exit check loop can make this a neat soln , not doing it , hehe.
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
    printf("HALO");
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
    printf("HALO");
    struct poly* curr2 = quad2->link;
    struct poly* lastnode = quad1->link;
    while(lastnode != NULL)
        lastnode=lastnode->link;
    while(curr2!=NULL)
    {
        bool nohitflag=true;
        struct poly* adder = quad1->link;
        while(adder!=NULL)
        {
            if(adder->px == curr2->px && adder->py == curr2->py)
            {
                nohitflag=false;
                break;
            }
            adder=adder->link;
        }
        if(nohitflag==true)
        {
            struct poly* temp = (struct poly*)malloc(sizeof(struct poly));
            temp->coeff = curr2->coeff;
            temp->px = curr2->px;
            temp->py = curr2->py;
            temp->link = NULL;
            lastnode->link = temp ;
            lastnode = lastnode->link;
        }
    }


    

}
