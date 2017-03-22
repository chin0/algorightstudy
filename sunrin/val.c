#include <stdio.h>

int main(void)
{
    int a=3;
    int b=4;

    printf("a의 값: %d \n",a);
    printf("b의 값: %d \n",b);
    printf("a의 시작 주소: 0x%lx \n",&a);
    printf("b의 시작 주소: 0x%lx \n",&b);
}
