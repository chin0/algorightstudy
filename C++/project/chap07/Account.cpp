#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int ID, int moeny, char *name)
    : accID(ID), balance(moeny)
{
    cusName=new char[strlen(name)+1];
    strcpy(cusName,name);
}

Account::Account(const Account &ref)
    : accID(ref.accID), balance(ref.balance)
{
    cusName=new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money)
{
    balance+=money;
}

int Account::WithDraw(int money)
{
    if(balance<money)
        return 0;

    balance-=money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout<<"계좌ID: "<<accID<<endl;
    cout<<"이 름: "<<cusName<<endl;
    cout<<"잔 액: "<<balance<<endl;
}

Account::~Account()
{
    delete []cusName;
}


