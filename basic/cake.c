#include <stdio.h>

struct line
{
    int one;
    int two;
};

int main(void)
{
    struct line line1,line2;

    scanf("%d %d",&line1.one,&line1.two);
    scanf("%d %d",&line2.one,&line2.two);

    if(line1.one > line2.one){
        if(line1.two < line2.two)
            printf("cross\n");
        else
            printf("not cross\n");
    } else if(line1.one < line2.one){
        if(line1.two > line2.two)
            printf("cross\n");
        else
            printf("not cross\n");
    } else
        printf("not cross\n");
}


