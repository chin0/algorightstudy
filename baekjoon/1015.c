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
    int A[50];
    int C[50];
    int result[50] = {0,};
    scanf("%d",&n);
    for(int i = 0; i<n;i++){
        scanf("%d",&temp);
        A[i] = temp;
        C[i] = temp;
    }

    qsort(A,n,sizeof(int),compare);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(C[i] == A[j]){
                printf("%d ",j + result[j]);
                result[j]++;
                break;
            }
                
        }
    }
     

    printf("\n");
    return 0;
}
