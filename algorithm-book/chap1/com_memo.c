#include <stdio.h>

//중복되는 결과를 검사하여 불필요한 계산을 없앤다
#define MAXN

long long memo[MAXN][MAXN];

long long choose_memo(int n,int r)
{

    if(memo[n][r] > 0)
        return memo[n][r];

    if(r == 0 || n ==r)
        return memo[n][r] = 1;

    return memo[n][r] = choose_memo(n - 1,r -1) + choose_memo(n -1 , r);
}
int main()
{
    int n,r;

    printf("input n,r: ");
    scanf("%d %d", &n,&r);
    printf("%lld\n",choose_memo(n,r));
    return 0;
}
