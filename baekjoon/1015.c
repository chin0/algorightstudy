#include <stdio.h>
#include <stdlib.h>

int compare(const void *first,const void *second)
{
    if(*(int*)first > *(int*)second)
        return 1;
    else if(*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(void)
{
    int n = 0;
    int temp = 0;
    int A[1000];
    int C[1000];
    scanf("%d",&n);
    for(int i = 0; i<n;i++){
        scanf("%d",&temp);
        A[i] = temp;
        C[i] = temp;
    }
    int P[n];

    qsort(A,3,sizeof(int),compare);
            

    printf("\n");
    return 0;
}
