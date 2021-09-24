#include "1_1.h"

void insertnode(struct head* top , int pos , int value)
{
    if(pos==0)//inseting at beginning
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = value;
        temp->link = top->link;
        top->link = temp;
        top->nodes=top->nodes+1;
        printf("\n-------------------------------------------------\n");
        printf("Node inserted :)");
        printf("\n-------------------------------------------------\n");
    }
    else if(pos == top->nodes)
    {
        struct node* curr = top->link;
        while(curr->link!=NULL)
            curr=curr->link;
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->link=NULL;
        curr->link=temp;
        top->nodes=top->nodes+1;
        printf("\n-------------------------------------------------\n");
        printf("Node inserted :)");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else if(pos > top->nodes || pos<0)
    {
        printf("\n-------------------------------------------------\n");
        printf("Stawwp trying to break me with wrong index :(");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else{
        struct node* curr = top->link;
        struct node* next = curr->link;
        int i=0;
        while(i!=pos-1)
        {
            curr=next;
            next=next->link;
            i++;
        }
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=value;
        curr->link=temp;
        temp->link=next;
        top->nodes=top->nodes+1;
        printf("\n-------------------------------------------------\n");
        printf("Node inserted :)");
        printf("\n-------------------------------------------------\n");
        return;
    }
}

void displaylist(struct head* top)
{
    if(top->nodes == 0)
    {
        printf("\n-------------------------------------------------\n");
        printf("The list has been empty all this time you doofus!");
        printf("\n-------------------------------------------------\n");
        return;
    }
    struct node* temp = top->link;
    printf("\n----------------------------------------------------\n");
    while(temp->link!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->link;
    }
    printf("%d ->NULL",temp->data);
    printf("\n-----------------------------------------------------\n");
    return;
}

void deletenode(struct head* top , int pos)
{
    printf("%d",top->nodes);
    if(pos > top->nodes)
    {
        printf("\n-------------------------------------------------\n");
        printf("Stawwp trying to break me with wrong index :(");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else if(top->nodes == 0)
    {
        printf("\n-------------------------------------------------\n");
        printf("There exists no nodes to be delete you good sir!");
        printf("\n-------------------------------------------------\n");
    }
    else if(pos == 0)
    {
        struct node* delnode = top->link;
        top->link = delnode->link;
        free(delnode);
        top->nodes=top->nodes-1;
        printf("\n-------------------------------------------------\n");
        printf("Node deleted!");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else if(pos == top->nodes)
    {
        struct node* prev = top->link;
        if(pos!=1)
        {
            struct node* delnode = prev->link;
            while(delnode->link!=NULL && delnode!=NULL)
            {
                prev=delnode;
                delnode=delnode->link;
            }
        }
        prev->link=NULL;
        top->nodes=top->nodes-1;
        printf("\n-------------------------------------------------\n");
        printf("Node deleted!");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else{
        struct node* prev = top->link;
        struct node* delnode = prev->link;
        struct node* next = delnode->link;
        int i=1;//0 is handled by other cases luckily
        while(i!=pos)
        {
            prev=delnode;
            delnode=next;
            next=next->link;
            i++;
        }
        prev->link=next;
        free(delnode);
        top->nodes=top->nodes-1;
        printf("\n-------------------------------------------------\n");
        printf("Node deleted!");
        printf("\n-------------------------------------------------\n");
        return;

    }
}

void nodeswap(struct head* top , int index1 , int index2)
{
    if(index1 == 0 || index2 == 0)
    {
        //need to fetch only index2 node
        int i=1; //index2 can only be 1 or greater, also helps with while loop
        struct node* prev = top->link; //0
        struct node* curr = prev->link; //1
        while(i!=index2 && i!=index1) //trying and hadling both cases , shorter code
        {
            prev=curr;
            curr=curr->link;
            i++;
        }
        struct node* link0 = top->link->link;
        struct node* sublink = curr->link;
        //trying to swap nodes without extra vars is too confoosing,remember 4 lines for swap
        prev->link=top->link;
        prev->link->link=sublink;
        top->link=curr;
        curr->link=link0;
        printf("\n-------------------------------------------------\n");
        printf("Nodes swapped :))");
        printf("\n-------------------------------------------------\n");
        return;
    }
    else{
        if(index1 > index2)
        {
            int temp=index1;
            index1=index2;
            index2=temp;
        }//doing this so i can do dual retrieval using one loop
        //we need to fetch both index1 and index2 , hence dual retrieval
        struct node* prev1 = top->link;
        struct node* curr1 = prev1->link;
        struct node* prev2 = top->link;
        struct node* curr2 = prev2->link;
        int i=1,j=1;
        while(j!=index2)//index2 is always greater , link line 181
        {
            if(i!=index1)
            {
                prev1=curr1;
                curr1=curr1->link;
                i++;
            }
            prev2=curr2;
            curr2=curr2->link;
            j++;
        }
        struct node* link0=curr1->link;
        struct node* sublink=curr2->link;
        if(index2-index1==1)//near by elements , bruh this is a corner case :slam:
        {
            curr1->link=curr2->link;
            curr2->link=curr1;
            prev1->link=curr2;
            printf("\n-------------------------------------------------\n");
            printf("Nodes swapped :))");
            printf("\n-------------------------------------------------\n");
            return;

        }
        prev1->link=curr2;
        curr2->link=link0;
        prev2->link=curr1;
        curr1->link=sublink;
        printf("\n-------------------------------------------------\n");
        printf("Nodes swapped :))");
        printf("\n-------------------------------------------------\n");
        return;
    }
}

void alterdelete(struct head* top)
{
    if(top->nodes == 0)
    {
        printf("\n-------------------------------------------------------------------\n");
        printf("Dear sir, there are no nodes, and you expect me to delete somthing!!");
        printf("\n-------------------------------------------------------------------\n");

    }
    if(top->nodes == 1)
    {
        printf("\n-------------------------------------------------------\n");
        printf("Only one node exists , there is alternative node for it?");
        printf("\n-------------------------------------------------------\n");
        return;

    }
    struct node* curr = top->link;
    while(curr->link!=NULL && curr->link->link!=NULL)//need to check both to avoid seg faults
    {
        curr->link=curr->link->link;
        curr=curr->link;
    }
    printf("\n-------------------------------------------------------\n");
    printf("Job done :))");
    printf("\n-------------------------------------------------------\n");
}
