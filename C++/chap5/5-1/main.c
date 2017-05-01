#include "4-3_2.h"

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);

    NameCard copy1=manClerk;
    copy1.ShowNameCardInfo();

    return 0;
}
