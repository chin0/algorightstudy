#include <iostream>

using namespace std;

class Factorial
{
private:
    int n;
public:
    Factorial(int n) : n(n)
    { }
    void get_number() const
    {
        cout << n << endl;
    }
    void get_factorial()
    {
        if(n <= 1)
            return 1;
        n = n * get_factorial(n-1);
    }
};


int main(void)
{
    Factorial fac(5);
    fac.get_factorial();
    fac.get_number();
}



