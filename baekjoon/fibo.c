#include <stdio.h>

//스택을 사용하지 않기때문에 속도가 빠르다. O(n)의 속도가 보장된다.
unsigned long long fibo(int n)
{
    //반복문을 이용한 피보나치 구하기
    if(n < 2)
        return n;

    unsigned long long result,previous = 1,pre_previous = 0;
    for(int i = 2; i<=n; i++)
    {
        //현재 수를 구하고
        result = previous + pre_previous;
        //전전 수열에 전 수의 값을 넣고
        pre_previous = previous;
        //전 수열에 현재 수의 값을 넣는다.
        previous = result;
    }
    return result;
}
int main(void)
{
    int n;
    scanf("%d",&n);

    printf("%llu\n",fibo(n));
}

