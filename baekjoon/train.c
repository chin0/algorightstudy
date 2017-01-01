#include <stdio.h>

int maxtrain(int in,int out,int current){
	int plus = in - out;
	return current + plus;
}
	
int main(void){
	int in,out;
	int current=0;
	int max = 0;
	for(int i =0;i<4;i++){
		scanf("%d %d",&out,&in);
		current = maxtrain(in,out,current);
		if(max < current)
			max = current;
	}
	printf("%d\n",max);

}

