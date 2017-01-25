#include <stdio.h>

//에라토스테네스의 체 변형. 수의 범위는 10000이하니까 100까지만 제곱해서 체크한다.

char eratos[10000];

void buildStick(){
    for(int i = 1;i<=100;i++){
        eratos[i * i] = 1;
    }
}

int main(void){
    buildStick();

    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int first = 0;
    int result = 0;
    for(int i = m; i<= n;i++){
        if(eratos[i] == 1){
            result += i;
            if(first == 0)
                first = i;
        }
    }
    if(first == 0){
        printf("-1\n");
        return 0;
    }
    printf("%d\n%d",result,first);
    printf("\n");
}

