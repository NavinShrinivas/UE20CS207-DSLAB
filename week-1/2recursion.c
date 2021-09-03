#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void swap(char* str , int i , int j)
{
    char temp = str[i];
    str[i]=str[j];
    str[j]=temp;
}
void permute(char* str , int l , int r)
{
    if(l==r)
        printf("%s \n",str);
    else{
        for(int i=l;i<=r;i++)
        {
            swap(str,l,i);
            permute(str , l+1 ,r); // swapping terms recursively
            swap(str , l ,i);//return string to original
        }
    }
}
int main(){
    char str[1000];
    printf("Enter string : ");
    scanf("%[^\n]%*c",str);
    int n=strlen(str);
    permute(str , 0 , n-1);
}