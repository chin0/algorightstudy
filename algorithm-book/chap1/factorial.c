#include <stdio.h>

int factorial(int a){
	int r = 1;
	while(a){
		r *= a--;
	}
	return r;
}

int main(void){
	printf("%d",factorial(10));
}
