#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d",&n);
    int result = 0;
    for(int i = 0; i<n; i++)
    {
        int temp;
        scanf("%1d",&temp);
        result+=temp;
    }
    printf("%d\n",result);
}

