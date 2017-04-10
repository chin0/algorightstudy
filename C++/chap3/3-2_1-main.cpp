#include "3-2_1.h"
#include <iostream>
using namespace std;

int main(void)
{
    Calc cal;
    cal.Init();

    cout << cal.Add(30,20) << endl;
    cout << cal.Div(20,3) << endl;
    cout << cal.Sub(20,2.5) << endl;
    cout << cal.Mul(2.4 ,1.2) << endl;

    cal.ShowOpCount();
}
