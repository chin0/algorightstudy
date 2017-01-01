#include <stdio.h>

void sort(int* arg,int len){
	int temp;
	for(int i = 0;i<len-1;i++){
		for(int j = 0;j < len - 1 -i;j++){
		   if(arg[j] > arg[j+1]){
			   temp = arg[j];
			   arg[j] = arg[j+1];
			   arg[j+1] = temp;
			}
		}
	}
}

int main(void){
	int n = 0;
	scanf("%d",&n);
	int c[n];
	for(int i = 0;i<n;i++){
		scanf("%d",&c[i]);
	}
	
	sort(c,n);
	for(int i = 0;i<n;i++){
		printf("%d\n",c[i]);
	}
	return 0;

}
	
