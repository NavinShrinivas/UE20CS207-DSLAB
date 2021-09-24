#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct polytop{
    struct poly* link;
};

struct poly{
    int coeff;
    int px;//power of x
    int py;//power of x
    struct poly* link; //link to next node
};
void inputquad(struct polytop* quad);
void displayquad(struct polytop* quad);
void addquads(struct polytop* quad1 , struct polytop* quad2);

