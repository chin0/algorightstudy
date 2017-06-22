#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
    if(num2==0)
        throw num2;
    cout<<"q: "<< num1 / num2 << endl;
    cout<<"r: "<< num1 % num2 << endl;
}

int main(void)
{
    int num1, num2;

    cout<<"input two number";
    cin >> num1 >> num2;

    try
    {
        Divide(num1, num2);
        cout<<"complete."<<endl;
    }
    catch(int expn)
    {
        cout<<"제수는 "<<expn<<"이 될수 없습니다."<<endl;
        cout<<"프로그램을 다시 실행하십시오."<<endl;
    }
    return 0;
}
