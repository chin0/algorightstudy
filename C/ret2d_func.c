#include <stdio.h>

int (*ret2c_func())[4]{
    static int ret[5][4] = { {3,3,3,3},{3,3,3,3},{3,3,3,3}}; //반환하면 스택에서 사라지기 때문에
    return ret;
}

int main(void)
{
    int (*ret)[4];
    ret = ret2c_func();

    printf("%d\n",ret[2][2]);
}
