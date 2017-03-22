#include <stdio.h>

int last_pos = 1;
int memo[100][2] = {{1,0},{0,1},{1,1}};
int memo_count = 2;

//동적계획법으로 구현한 팩토리얼. 동적계획법: 답을 재사용하는 설계기법.

int fibonacci(int n) {
    int i = 0;
    if(memo_count < n){
        for(int i=memo_count+1; i<=n; i++)
        {
            memo[i][0] = memo[i-1][0] + memo[i-2][0];
            memo[i][1] = memo[i-1][1] + memo[i-2][1];
        }
        memo_count = n;
    }
    printf("%d %d\n",memo[n][0],memo[n][1]);
    
}
int main(void)
{
    int t,temp;

    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d",&temp);
        fibonacci(temp);
    }
}

        

        
