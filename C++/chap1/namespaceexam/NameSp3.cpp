#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void);
}
namespace BestComImpl
{
    void PrettyFunc(void);
}
namespace ProgComImpl 
{
    void SimpleFunc(void);
}

int main()
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    return 0;
}
void BestComImpl::SimpleFunc(void)
{
    std::cout << "SimpleFunc implenmented by BestCom" << std::endl;
    PrettyFunc(); //same namespace
    ProgComImpl::SimpleFunc();//different namespace 
}
void BestComImpl::PrettyFunc()
{
    std::cout << "So pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
    std::cout << "SimpleFunc implenmented by BestCom" << std::endl;
}
