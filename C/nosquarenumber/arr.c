#include <stdio.h>
#include <stdlib.h>

int* getnum(int start,int end){
    int* array = (int*)calloc(end - start,sizeof(int));
    int i = 2;
    while(i * i < n){
        printf("%d ", i*i);
        for(int j = 1; j<=n;j++){
            if(j % (i * i) == 0)
                array[j-1] = 1;
        }
        i++;
    }
    return array;
}
int main(void){
    int start,end;
    int result = 0;
    for(int i=1;i<=100;i++){
        if(arr[i-1] == 0)
            result++;
    }

}
