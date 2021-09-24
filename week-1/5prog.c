#include "5_1.h"


int main(){
    struct player pls[10000];
    int no_pl = 0;
    while(true)
    {

        int choice;
        printf("1.Enter player details\n");
        printf("2.Display top player in a match\n");
        printf("3.Display number of matches played by a player\n");
        printf("4.Exit \n");
        printf("Enter choice :");
        scanf("%d",&choice);
        if(choice==4)
            return 0;
        else if(choice == 1)
        {
            printf("Player details : \n");
            printf("\tEnter Name :");
            scanf("\t%[^\n]%*c",(pls+no_pl)->name);
            printf("\tEnter team : ");
            scanf("%[^\n]%*c",(pls+no_pl)->team);
            for(int i=0;i<14;i++)
            {
                printf("match %d details for above player :\n",i+1);
                printf("\tMatch played?[Y/n]:");
                char p;
                scanf("\t%c",&p);
                if(p=='n')
                {
                    (pls+no_pl)->match_data.score[i]=0;
                    (pls+no_pl)->match_data.played[i]=false;
                }
                else{
                    int s;
                    printf("\tEnter runs scored in this match : ");
                    scanf("%d",&s);
                    (pls+no_pl)->match_data.score[i]=s;
                    (pls+no_pl)->match_data.played[i]=true;
                }
               /* printf("%d",(pls+no_pl)->match_data.score[i]);//debugging step*/   
            }
            no_pl++;
        }
        else if(choice == 2)
        {
            if(no_pl==0)
                printf("Bruh there is no data of players to search in");
            else{
                int mat;
                printf("Enter match number to find top player[0-13]: ");
                scanf("%d",&mat);
                int top = topplayer(pls,mat,no_pl);
                printf("Doing linear search on player data...\n");
                printf("Details of top scorer in this match : \n");
                printf("\tName : %s\n",(pls+top)->name);
                printf("\tTeam : %s\n",(pls+top)->team);
                printf("\tScore : %d\n",(pls+top)->match_data.score[mat]);
            }
        }
        else if(choice == 3)
        {
            printf("Enter player number [0-%d] :",no_pl-1);
            int pno;
            scanf("%d",&pno);
            int ret = matchpl(pls,pno);
            printf("\t Total number of matches played : %d \n",ret);
        }

    }
}
