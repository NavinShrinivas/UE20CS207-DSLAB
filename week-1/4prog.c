#include<stdio.h>

typedef long long int ll;
#define intlimit 2147483647;

// void swap(int a[],int i,int j)
// {
//     int temp=a[i];
//     a[i]=a[j];
//     a[j]=temp;
// }
void tower_of_hanoi(int n , char from , char between , char to)
{
    if(n==1)
    {
        printf("From : %c to %c\n",from,to);
        return;
    }
    tower_of_hanoi(n-1,from,to,between);
    printf("From : %c to %c\n",from,to);
    tower_of_hanoi(n-1,between,from,to);
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    //the number fo moves needed by n disks is 2^n-1 always
    int n;
    printf("Enter number of disks : ");
    scanf("%d",&n);
    tower_of_hanoi(n,'A','B','C'); //considering the three disks to be called A B and C
    //i : 1->ans
    //I writing down nice interative solution
    //S-Source , D-Destination , A-Auxilary
    //if i%3==1 : S <-> D 
    //if i%3==2 : S <-> A
    //if i%3==0 : A <-> S
    //but a interative solution needs a stack imple sadly , as this % logic can
    //tell between what towers the operation is , but cant tell which direction
    //and that need a comparision of sizes on both towers , hence the "<->"
    //let's implement recursive solution
}
