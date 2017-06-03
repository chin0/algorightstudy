#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x;
    scanf("%d",&x);
    char a[6];
    sprintf(a,"%d",x);
    for(int i = 4;i>=0;i--)
        printf("%c ",a[i]);
}
