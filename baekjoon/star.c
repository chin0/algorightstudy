#include <stdio.h>

void star(int linenum){
	switch(linenum % 3){
		case 0:
			printf("  *  ");
			return;
		case 1:
			printf(" * * ");
			return;
		case 2:
			printf("*****");
			return;
	}
}
void draw(int line,int maxsize){
	if(line == 0)
		return;
	draw(line - 1,maxsize / 2 - ,49);
	for(int i = 0;i < spacesize;i++){
		printf(" ");
	}
	star(line);
	for(int i =0;i < spacesize;i++){
		printf(" ");
	}
	printf("\n");
}

int main(void){
	draw(1,22,49);
}

