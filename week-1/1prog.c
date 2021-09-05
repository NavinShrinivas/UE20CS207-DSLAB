#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool recusrsesub(char* string , char* substring , int n , int start){
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(string[start+i]==substring[i])
            continue;
        else
            flag=0;
    }
    if(flag==1)
        return true;
    else if(string[start]='\0')
        return false;
    else
        recusrsesub(string , substring , n , start+1);
}
int main(){
    char string[1000];
    char substring[1000];
    printf("Enter string : ");
    scanf("%[^\n]%*c",string);
    // // printf("The sting : %s",string);
    printf("Substring to search for : ");
    scanf("\t%[^\n]%*c",substring);
    int len = strlen(substring);
    if(recusrsesub(string , substring , len , 0))
        printf("True\n");
    else
        printf("False\n");
}