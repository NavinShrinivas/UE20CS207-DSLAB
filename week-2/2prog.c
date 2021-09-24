#include"2_1.h"

int main(){
    struct polytop* quad1 = (struct polytop*)malloc(sizeof(struct polytop));
    struct polytop* quad2 = (struct polytop*)malloc(sizeof(struct polytop));
    inputquad(quad1);
    inputquad(quad2);
    addquads(quad1,quad2);
    displayquad(quad1);
}
