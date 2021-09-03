#include<stdio.h>
#include<stdlib.h>

int binarysearch(int* a , int l , int r , int e) //assuming acending array
{
    if(l>=r)
        return -1;
    
    int mid = (l+r+1)/2;
    if(a[mid]==e)
        return mid;
    else if(a[mid]>e)
        binarysearch(a,l,mid-1,e);
    else
        binarysearch(a,mid,r,e);
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
    int search_ele;
    printf("Enter element for searching : ");
    scanf("%d",&search_ele);
    int pos=binarysearch(a,0,n,search_ele);
    if(pos==-1)
        printf("Not found! \n");
    else 
        printf("Found at : %d \n",pos+1);
}