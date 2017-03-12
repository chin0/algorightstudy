#include <stdio.h>

int main(void)
{
    int x,result;

    scanf("%d",&x);
    
    result = (3 * (x * x * x * x * x)) + (2 * (x * x * x * x)) + (5 * (x * x * x)) + (x * x) + 7 * x - 6;

    printf("result: %d\n",result);
    
    return 0;
}

