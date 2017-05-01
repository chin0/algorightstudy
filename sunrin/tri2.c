#include<stdio.h>

int n, ret;

int max(int x, int y){
    if(x > y) return x;
    return y;
}

int main(void){
    int i, jmax, jmin;
    scanf("%d",&n);
    for(i=1;i<=n/3;i++){
        jmax = n-i; //가장 큰 변
        jmin = max(2*i, n-2*i+1);
        printf("%d %d %d\n",jmax,jmin,jmax/2 - (jmin+1)/2 + 1);
        ret += jmax/2 - (jmin+1)/2 + 1;
    }
    printf("%d\n",ret);
}
