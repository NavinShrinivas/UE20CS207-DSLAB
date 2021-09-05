#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter number fo elements in the array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array : \n");
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        a[i]=c;
    }
    int search_ele;
    printf("Enter element for searching : ");
    scanf("%d",&search_ele);
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==search_ele)
            pos=i;
    }
    if(pos==-1)
        printf("Not found! \n");
    else 
        printf("Found at : %d \n",pos);
}