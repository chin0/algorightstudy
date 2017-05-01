#include <stdio.h>

int fuck(int a, int b, int c)
{
    return ((a > b) ? 
            ((a > c) ? a : c) :
            ((b > c) ? b : c));
}

int main(void)
{
    int n,k,cnt=0,cnt2=0;

    scanf("%d",&n);
    int _max = (n % 2) ? n/2+1 : n/2;
    int a = n % 2;
    int __min = 0;


    for(int i = 1; i <= n/3+1; i++){
        for(int j = _max/2; j < _max+1; j++){
            int temp = n-i-j;
            if(i <= j && j <= temp && i+j+temp == n && temp < _max)
                cnt += 1;
        }
    }   
    printf("%d\n",cnt);
}


