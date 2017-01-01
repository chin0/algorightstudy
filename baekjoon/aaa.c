#include <stdio.h>

int main(void){
	int (*p)[];
	int a[6][5];
	p = a;
	a[1][2] = 123;
	printf("%d\n",*(*(a + 1) + 2));
}
