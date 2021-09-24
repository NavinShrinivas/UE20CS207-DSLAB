#include "5_1.h"

int topplayer(struct player* pls , int mat , int no_pl)
{
    int max_ind = 0;
    int max = pls->match_data.score[mat];
    for(int i=1;i<=no_pl;i++)
    {
        if((pls+i)->match_data.score[mat]>max)
        {
            max=(pls+i)->match_data.score[mat];
            max_ind=i;
        }
    }
    return max_ind;

}

int matchpl(struct player* pls , int pno)
{
    int played=0;
    for(int i=0;i<14;i++)//14 match details always
    {
        if((pls+pno)->match_data.played[i]==true)
            played++;
    }
    return played;
}
