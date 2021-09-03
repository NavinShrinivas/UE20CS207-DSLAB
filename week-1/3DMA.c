#include "3_1.h"

int main(){
    int n;
    printf("Enter number of students : ");
    scanf("%d",&n);
    struct student stu [n];
    for(int i=0;i<n;i++)
    {
        printf("Details for student %d : \n",i+1);
        printf("Enter name : ");
        scanf("\t%[^\n]%*c",(stu+i)->name);
        printf("Enter SRN : ");
        scanf("\t%[^\n]%*c",(stu+i)->srn);
        printf("Enter semester : ");
        scanf("%d",&((stu+i)->sem));
        printf("Enter marks in phy : ");
        scanf("%d",&((stu+i)->py));
        printf("Enter marks in chem : ");
        scanf("%d",&((stu+i)->cy));
        printf("Enter marks in cs : ");
        scanf("%d",&((stu+i)->cs));
        printf("Enter marks in math : ");
        scanf("%d",&((stu+i)->ma));
        printf("Enter marks in bio : ");
        scanf("%d",&((stu+i)->bt));
    }
    while(1)
    {
        printf("\n1.Find average\n");
        printf("2.Sorted display\n");
        printf("3.Exit\n");
        int choice;
        printf("Enter choice : ");
        scanf("%d",&choice);

        if(choice==3)
            return 0;
        else if(choice == 1)
        {
            printf("Subject codes : cy , py , cs , ma , bt \n");
            printf("Enter subject code to find average : ");
            char code[3];
            scanf("\t%[^\n]%*c",code);
            int ret = findavg(code , stu , n);
            if(ret == -3)
                printf("Invalid code! \n");
            else
                printf("Average : %d",ret);
        }
        else
        {
            sortedisp(stu , n);
            for(int i=0;i<n;i++)
            {
                printf("Details of student %d : \n",i+1);
                printf("name : %s \n" , stu->name);
                printf("SRN : %s \n" , stu->srn);
                printf("semester : %d \n" ,stu->sem);
                printf("marks in phy : %d \n",stu->py);
                printf("marks in chem : %d \n",stu->cy);
                printf("marks in cs : %d \n",stu->cs);
                printf("marks in math : %d \n",stu->ma);
                printf("marks in bio : %d \n",stu->bt);
            }
        }

    }
}