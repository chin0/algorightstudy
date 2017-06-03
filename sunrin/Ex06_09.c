#include <stdio.h>

void TestLocal(void);

int main(void)
{
    TestLocal();
    TestLocal();

    return 0;
}

void TestLocal(void)
{
    int num = 0;
    printf("num = %d\n",num++);
}
