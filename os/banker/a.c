#include <iostream>

int& retbigref(int &a,int &b)
{
    //C++은 함수의 리턴값을 Lvalue에 넣을수있다.
    //참조형을 리턴할때는 절대 일반 지역변수를 리턴하지말것(이미 반환된 스택이기때문)
    //즉 반환은 포인터, 전역변수, 참조형 인자만 된다.
    return (a > b) ? a : b;
}

int main(void)
{
    int a=10,b=20;

    std::cout << "a: " << a << " " << "b: " << b << std::endl;

    std::cout << "int& retbigref's return value: " << retbigref(a,b) << std::endl;
    std::cout << "int& retbigref's return value=0x30: " << std::endl;
    retbigref(a,b) = 0x30;
    std::cout << "a: " << a << " " << "b: " << b << std::endl;
}
