#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define STACKSIZE 100

struct stack{
    int top;
    char data[STACKSIZE];
};

void pushe(struct stack* st , char d);
void displaystack(struct stack* st);
char peekstack(struct stack* st);

