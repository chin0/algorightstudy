#include <stdio.h>

int com(int n,int r)
{
    if(n == 1 || n==r)
        return 1;
    return com(n-1,r-1) + com(n-1,r);
}
int main(void)
{
    printf("%d\n",com(5,2));
}
