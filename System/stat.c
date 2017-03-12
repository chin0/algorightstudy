#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    struct stat sb;
    int ret;

    if(argc < 2){
        fprintf(stderr,
                "usage: %s <file>\n", argv[0]); return 1;
    }

    ret = stat(argv[1],&sb);
    if(ret){
        perror("stat");
        return 1;
    }

    printf("%s is %ld bytes\n", argv[1],sb.st_size);
    return 0;
}

