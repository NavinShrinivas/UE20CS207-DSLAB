
#include"3_1.h"

int findavg(char* code , struct student* stu , int n)
{
    if( (strcmp(code , "cy") || (strcmp(code , "py") || strcmp(code , "ma")) || (strcmp(code , "bt") || strcmp(code , "cs"))) !=0)
        return -3;
    else
        if(strcmp(code , "cy")==0)
        {
            int average=0;
            for(int i=0;i<n;i++)
            {
                average+=stu->cy;
            }
            average/=n;
            return average;
        }
        if(strcmp(code , "ma")==0)
        {
            int average=0;
            for(int i=0;i<n;i++)
            {
                average+=stu->ma;
            }
            average/=n;
            return average;
        }
        if(strcmp(code , "bt")==0)
        {
            int average=0;
            for(int i=0;i<n;i++)
            {
                average+=stu->bt;
            }
            average/=n;
            return average;
        }
        if(strcmp(code , "cs")==0)
        {
            int average=0;
            for(int i=0;i<n;i++)
            {
                average+=stu->cs;
            }
            average/=n;
            return average;
        }
        if(strcmp(code , "py")==0)
        {
            int average=0;
            for(int i=0;i<n;i++)
            {
                average+=stu->py;
            }
            average/=n;
            return average;
        }

}
void swap(struct student* stu , int a , int b)
{
    struct student temp = *(stu+a);
    *(stu+a)=*(stu+b);
    *(stu+b)=temp;
}
void sortedisp(struct student* stu , int n)
{
    int c=0;
    while(c<n)
    {
        for(int i=0;i<c;i++)
        {
            if(strcmp((stu+i)->srn , (stu+i+1)->srn) > 0)
                swap(stu , i , i+1);
        }
        c++;
    }
}
