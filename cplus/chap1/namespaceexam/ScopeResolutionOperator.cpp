#include <iostream>

int val=100;

int SimpleFunc(void)
{
    int val=20;
    val+=3;//이 경우 전역변수는 지역변수에 의해 가려진다.
    return val;
}

int SimpleFunc2(void)
{
    int val=20;
    ::val+=3;//범위지정 연산자를 통해 전역변수를 가리킨다.
    return val;
}
