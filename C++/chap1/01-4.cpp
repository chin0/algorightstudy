#include <iostream>

int main(void)
{
    int won;
    while(true)
    {
        std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin >> won;
        
        if(won == -1)
            break;

        std::cout << "이번 달 급여: " << 50 + won  * 0.12 << "만원" << std::endl;
    }
}

