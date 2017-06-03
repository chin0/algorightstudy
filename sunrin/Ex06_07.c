#include <stdio.h>

void PrintCount(void);

int main(void)
{
    int count = 0;
    
    printf("main count = %d\n", count);

    return 0;
}

void PrintCount(void)
{
    //error!
    //printf("PrintCount: count = %d\n",count); 
}
