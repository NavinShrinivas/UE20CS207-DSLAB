#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct head{
    struct details* link;
    int num;
};
struct details{
    char name[100];
    int number;
    char address[1000];
    struct details *llink,*rlink;
};
void enterdetails(struct head* top);
void display(struct head* top);

