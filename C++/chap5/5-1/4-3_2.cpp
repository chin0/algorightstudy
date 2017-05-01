#include "4-3_2.h"

NameCard::NameCard(char* n, char* c_name, char* p_num, int c_pos)
    : comp_pos(c_pos)
{ 
    name = new char[strlen(n)+1];
    company_name = new char[strlen(c_name)+1];
    phone_num = new char[strlen(p_num) + 1];
    
    strcpy(name,n);
    strcpy(company_name,c_name);
    strcpy(phone_num,p_num);
}

NameCard::NameCard(const NameCard &copy) : comp_pos(copy.comp_pos)
{
    name = new char[strlen(copy.name)];
    company_name = new char[strlen(copy.company_name)];
    phone_num = new char[strlen(copy.phone_num)];

    strcpy(name,copy.name);
    strcpy(company_name,copy.company_name);
    strcpy(phone_num, copy,phone_num);
}
NameCard::~NameCard()
{
    delete name[];
    delete company_name[];
    delete phone_nump[];
}
void NameCard::ShowNameCardInfo() const
{
    cout << "이름: " << name << endl;
    cout << "회사: " << company_name << endl;
    cout << "전화번호: " << phone_num << endl;
    cout << "직급: ";

    switch(comp_pos){
        case COMP_POS::CLERK:
            cout << "사원" << endl;
            break;
        case COMP_POS::SENIOR:
            cout << "주임" << endl;
            break;
        case COMP_POS::ASSIST:
            cout << "대리" << endl;
            break;
        case COMP_POS::MANAGER:
            cout << "과장" << endl;
            break;
    }
}

