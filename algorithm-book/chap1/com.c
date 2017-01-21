#include <stdio.h>

long long combination(int n, int r)
{
    if(r == 0 || n == r)
        return  1;
    return combination(n-1,r-1) + combination(n-1,r);
}

int main()
{
    int n,r;

    scanf("%d %d", &n,&r);
    printf("%lld\n",combination(n,r));
    return 0;
}

