#include <stdio.h>
#include <stdlib.h>

int** mallocArray(int width,int height){
	int **arr = (int**)malloc(sizeof(int*) * height);
	arr[0] = (int*)malloc(sizeof(int*) * width);

	for(int i=1;i<height;i++){
		arr[i] = arr[i-1] + width;
	}
	return arr;
}
void freeArray(int** arr){
	free(arr[0]);
	free(arr);
}
int main(void){
	int **arr = mallocArray(8,6);
	arr[0][1] = 123;
	printf("%d\n",(*arr)[1]);
	return 0;
}
