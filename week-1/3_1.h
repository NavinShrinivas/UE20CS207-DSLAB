#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[20];
    char srn[20];
    int sem;
    int py;
    int cy;
    int ma;
    int cs;
    int bt;
};

int findavg(char* code , struct student* stu , int n);

void sortedisp(struct student* stu , int n);