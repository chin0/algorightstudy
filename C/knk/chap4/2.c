#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    
    scanf("%d",&a);
    
    b = a % 10;
    c = a % 100 / 10;
    d = a / 100;

    printf("%.1d%.1d%.1d\n",b,c,d);
    
    return 0;
}

    
