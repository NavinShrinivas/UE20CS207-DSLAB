#include"3_1.h"

void pushe(struct stack* st , char d)
{
    if(st->top == STACKSIZE-1)
    {
        return;
    }
    else{
        (st->top)++;
        st->data[st->top]=d;
        return;
    }
}

void displaystack(struct stack* st)
{
    for(int i=0;i<=st->top;i++)
    {
        printf("%c",st->data[i]);
    }
}

char peekstack(struct stack* st)
{
    return st->data[st->top];
}
