#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct matches{
    bool played[14];
    int score[14];
};

struct player{
    char name[20];
    char team[10];
    struct matches match_data;
};

int topplayer(struct player* pls , int mat , int no_pl);
int matchpl(struct player* pls , int pno);
