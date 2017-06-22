#include <iostream>
#include <cstring>
using namespace std;

class DepositException
{
private:
    int reqDef;
public:
    DepositMoney(int money) : repDef(money)
    { }
    void ShowExceptionReason()
    {
        cout<<"[예외 메시지: "<<reqDef<<
    }

}