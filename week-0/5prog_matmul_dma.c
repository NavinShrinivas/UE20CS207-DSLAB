#include<stdio.h>
#include<stdlib.h>

void matrixmul(int n , int** a, int** b, int** ans)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i][j]=0;
            for(int k =0 ;k<n;k++)
            {
                ans[i][j]+=a[i][k]*b[k][i];
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter size of matrix : ");
    scanf("%d",&n);
    int *a[n],*b[n],*ans[n];
    printf("Enter elements of matrix 1 :\n");
    for(int i=0;i<n;i++)
    {
        *(a+i)=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            int c;
            scanf("%d",&c);
            *(*(a+i)+j)=c;
        }
    }
    printf("Enter elements of matrix 2 : \n");
    for(int i=0;i<n;i++)
    {
        *(b+i)=(int*)malloc(n*sizeof(int));
        *(ans+i)=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            int c;
            scanf("%d",&c);
            *(*(b+i)+j)=c;
        }
    }
    matrixmul(n,a,b,ans);
    printf("After Multiplication :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}