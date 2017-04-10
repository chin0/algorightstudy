#include <stdio.h>

int main(void)
{
    int a,b,max,tmp;

    printf("두 수를 입력하시오 ->");
    scanf("%d %d",&a, &b);
    if(a < b){
        max = b;
    } else {
        max = a;
    }

    printf("\u2588최대값=%d\n",max);


    return 0;
}

