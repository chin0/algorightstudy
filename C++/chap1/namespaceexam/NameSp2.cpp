#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void);
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
}
void ProgComImpl::SimpleFunc(void)
{
    std::cout << "SimpleFunc implenmented by BestCom" << std::endl;
}
