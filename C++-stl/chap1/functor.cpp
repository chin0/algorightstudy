#include <iostream>
using namespace std;

struct FuncObject
{
public:
    void operator()(int arg) const
    {
        cout << "integer: " << arg << endl;
    }
};

void Print1(int arg)
{
    cout << "integer: " << arg << endl;
}

int main()
{
    void (*Print2)(int) = Print1;
    FuncObject Print3;

    Print1(10);
    Print2(20);
    Print3(30);

    return 0;
}