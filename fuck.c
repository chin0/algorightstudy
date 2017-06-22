#include <stdio.h>
#include <stdlib.h>

int bSearch(int *a, int value, int low, int high)
{
    if(high < low)
        return -1;
    int mid = (low + high) / 2;
    if(a[mid] > value)
        return bSearch(a, value, low, mid-1);
    else if(a[mid] < value)
        return bSearch(a, value, mid+1, high);
    else
        return mid + 1;
}

int main(void)
{
    int n,m,temp;
    scanf("%d",&n);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        scanf("%d",&temp);
        printf("%d ", bSearch(arr,temp,0,n-1));
    }
}
        
    
