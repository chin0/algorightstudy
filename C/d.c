#include <stdio.h>

int main(void)
{
	int a;
	scanf("%5d",&a);
	
	printf("[%d]\n", a / 10000 * 10000);
	a %= 10000;
	printf("[%d]\n", a / 1000 * 1000);
	a %= 1000;
	printf("[%d]\n", a / 100 * 100);
	a %= 100;
	printf("[%d]\n", a / 10 * 10);
	a %= 10;
    printf("[%d]\n",a);
}
	
