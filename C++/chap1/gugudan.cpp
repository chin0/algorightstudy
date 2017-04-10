#include <iostream>

int main(void)
{
    int x;
    std::cin >> x;

    for(int i = 1; i<=9; i++)
    {
        std::cout << x << " * " << i << "=";
        std::cout << x * i << std::endl;
    }
}

        
