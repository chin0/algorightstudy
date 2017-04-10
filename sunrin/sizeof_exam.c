#include <stdio.h>

int main(void)
{
    char ch;
    int num;
    double fnum;

    printf("ch의 바이트 크기: %d\n", sizeof ch);
    printf("num의 바이트 크기: %d\n", sizeof num);
    printf("fnum의 바이트 크기: %d\n", sizeof fnum);
    printf("char의 바이트 크기: %d\n", sizeof(char) );
    printf("short의 바이트 크기: %d\n", sizeof(short));
    printf("int의 바이트 크기: %d\n", sizeof(int) );
    printf("long의 바이트 크기: %d\n", sizeof(long));
    printf("float의 바이트 크기: %d\n", sizeof(float));
    printf("double의 바이트 크기: %d\n", sizeof(double));
}

