#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "SimpleFunc implenmented by BestCom" << std::endl;
    }
}
namespace ProgComImpl 
{
    void SimpleFunc(void)
    {
        std::cout << "SimpleFunc implenmented by BestCom" << std::endl;
    }
}

int main()
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    return 0;
}
