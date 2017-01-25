#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char bigint[604];
char bigint2[604];
int cur=6;
unsigned long long memo[101][101];

extern inline int atochar(char a){
    return '0' + a;
}
//하나하나 다하면 시간이 너무 오래걸리므로 메모이제이션 활용.
//매우 큰 정수를 처리해야한다. 이거 구현할것.
void bigadd(char* a,char* a1){
    for(int i = 0;i<cur;i++){
        int temp1 = a[i] + a1[i];
        if(temp1 >= 10){
            a[i+1] += 1;
            a[i] = temp1 % 10;
        }
        else
            a[i] = temp1;
    }
    if(a[cur] > 0)
        cur++; 
}
unsigned long long int combination(int n,int r){
    long long ret = 0;
    if(n == r || r == 0)
        return 1;
    if(memo[n][r])
        ret = memo[n][r];
    else
        ret = memo[n][r] = combination(n-1,r-1) + combination(n-1,r);
    return ret;
}

int main(void){
    int n,r=0;
    for(int i = 0;i<6;i++){
        bigint[i] = i;
        bigint2[i] = i;
    }
    bigadd(bigint,bigint2);
    printf("cur: %d\n",cur);
    for(int i=cur;i>=0;i--)
        printf("%c",atochar(bigint[i]));
    printf("\n");
}
