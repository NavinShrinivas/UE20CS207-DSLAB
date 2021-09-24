#include<stdio.h>
#include<stdlib.h>


struct head{
    struct node* link;
    int nodes;
};

struct node{
    int data;
    struct node* link;
};

void insertnode(struct head* top , int pos , int value);
void displaylist(struct head* top);
void deletenode(struct head* top,int pos);
void nodeswap(struct head* top , int index1 , int index2);
void alterdelete(struct head* top);
