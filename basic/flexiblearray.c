#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagFlexible{
    unsigned int header1;
    unsigned int header2;
    char flexible[]; //or [0],[1]
}flexible;

int main(int argc,char** argv){
    
    if(argc < 3){
        printf("usage: %s <size> <data>\n",argv[0]);
        return 0;
    }
    printf("sizeof flexible data structure: %lu\n",sizeof(flexible));
    flexible *data = (flexible*)malloc(sizeof(flexible) + sizeof(char) * atoi(argv[1]));
    
    if(strlen(argv[2]) > (size_t)atoi(argv[1])){
        printf("buffer overflow!!\n");
        exit(1); 
    }

    strcpy(data->flexible,argv[2]);

    printf("data : %s\n",data->flexible);
    free(data);
    return 0;
}
    

