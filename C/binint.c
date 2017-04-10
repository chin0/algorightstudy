#include <stdio.h>

int bigint[2005];
int carry=0;

void power()
{
    int curcarry = carry;
    for(int i = curcarry; i >= 0; i--){
        if(bigint[i] * 2 >= 10){
            if(i == curcarry)
                carry++;
            bigint[i] = (bigint[i] * 2) % 10;
            bigint[i+1] += 1;
        }else
            bigint[i] *= 2;
    }
}

int main(void)
{
    bigint[0] = 2;
    for(int i = 0; i < 1999; i++)
        power();

    printf("%d\n",carry);
    
    for(int i = carry; i >= 0; i--)
        printf("%d",bigint[i]);
    printf("\n");
}


        
    
