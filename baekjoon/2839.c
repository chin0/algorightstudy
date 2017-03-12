#include <stdio.h>

int solve(int a)
{
    int min=1000000,temp,curmin;
    
    for(int i = 0; i < (5000/3); i++)
    {
        for(int j = 0; j < (5000/5); j++)
        {
            temp = (i*3) + (j*5);
            curmin = i+j;
            if(temp == a)
                if(min > curmin)
                    min = curmin;
        }
    }
    if(min == 1000000)
        return -1;
    return min;
}


            
int main(void)
{
    int num = 0;
    scanf("%d",&num);
    printf("%d\n",solve(num));
}
