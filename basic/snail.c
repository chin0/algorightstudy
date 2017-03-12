#include <stdio.h>

int main(void)
{
    int num, i, j, k, cnt = 0;
    int arr[50][50] = {0, };

    scanf("%d", &num);

    for(k=0; k<(num+1)/2; ++k) {
        for(j=k; j<num-k-1; ++j)
            arr[k][j] = ++cnt;
        for(i=k; i<num-k-1; ++i)
            arr[i][num-k-1] = ++cnt;
        for(j=num-k-1; j>=k; --j)
            arr[num-k-1][j] = ++cnt;
        for(i=num-k-2; i>=k+1; --i)
            arr[i][k] = ++cnt;
    }

    for(i=0; i<num; ++i) {
        for(j=0; j<num; ++j)
            printf("%3d", arr[i][j]);
        printf("\n");
    }
}


