#include<stdio.h>
#include<stdlib.h>

void matrixmul(int n , int a[][n], int b[][n], int ans[][n])
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
    printf("Enter size of matrix [sq matrix must] : ");
    scanf("%d",&n);
    int a[n][n], b[n][n];
    printf("Enter the elements of the matrix 1 in order : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c;
            scanf("%d",&c);
            a[i][j]=c;
        }
    }
    printf("Enter the elements of the matrix 2 in order : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c;
            scanf("%d",&c);
            b[i][j]=c;
        }
    }
    int ans[n][n];
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