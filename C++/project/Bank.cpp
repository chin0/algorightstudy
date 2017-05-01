#include <iostream>
#include <cstring>
#include "Bank.h"
#define MAX 10

using namespace std;

account::account(int id = 0, int money = 0; char *name=NULL) : id(id),money(moeny)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
account::~account()
{
    delete name[];
}

account::int withdraw(int money)
{
    if(this->money < moeny)
        return 0;
    this->money -= money;
    return money;
}
    
account::void deposit(int money)
{
    this->money += money;
}

account::void printInformation()
{
    cout << "계좌ID: " << id << endl;
    cout << "이름 : " << name << endl;
    cout << "잔액 : " << money << endl;
}

account:: int getId(){ return id };

account *user[100];
void print_menu();
void bank_join();
void bank_deposit();
void bank_withdraw();
void bank_printmem();

int main(void)
{
    int num;
loop:
    print_menu();
    cin >> num;
    
    if(num < 5){
        funclist[num-1]();
        goto loop;
    }

    return 0;
}
inline int findId(int id)
{
    int i=0;
    while(id != user[i].id && i != accnum)
    {
        i++;
    }
    return i;
}

void print_menu()
{
    cout << "1. 계좌계설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 나가기" << endl;
    cout << "선택: ";
}
void bank_join()
{
    cout << "========[계좌계설]========" << endl;
    cout << "계좌ID:";
    cin >> user[accnum].id;
    cout << "키미노 나마에와?:";
    cin >> user[accnum].name;
    cout << "입금액:";
    cin >> user[accnum].remain;
    accnum++;
}
void bank_deposit()
{
    int id;
    int target;
    int add_money;
    cout << "========[입  금]========" << endl;
    cout << "계좌ID:";
    cin >> id;
    target = findId(id);
    cout << "입금액: ";
    cin >> add_money;
    user[target].remain += add_money;
    cout << "끗" << endl;
}
    
void bank_withdraw()
{
    int id;
    int target;
    int sub_money;
    cout << "========[출  금]========" << endl;
    cout << "계좌ID:";
    cin >> id;
    target = findId(id);
    cout << "출금액: ";
    cin >> sub_money;
    user[target].remain -= sub_money;
    cout << "끗" << endl;
}

void bank_printmem()
{
    int target;
    int id;
    cout << "계좌ID:";
    cin >> id;
    target = findId(id);
    cout << "이름: " << user[target].name << endl;
    cout << "잔액: " << user[target].remain << endl;
}

