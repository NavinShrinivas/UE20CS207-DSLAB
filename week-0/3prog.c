#include<stdio.h>
#include<stdlib.h>


void swap(int* a, int n , int m)
{
    int tem = a[n];
    a[n]=a[m];
    a[m]=tem;
}
void bubblesort(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(a[j]>a[j-1])
                swap(a,j,j-1);
        }
    }
}

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
    bubblesort(a,n);
    printf("Array after sorting : \n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}