//
// Created by kafuuchin0 on 04.06.17.
//

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, char *name)
        : accId(ID), balance(money)
{
    cusName=new char[strlen(name)+1];
    strcpy(cusName,name);
}

Account::Account(const Account &ref)
    : accId(ref.accId), balance(ref.balance)
{
    cusName=new char[strlen(ref.cusName)+1];
    strcpy(cusName,ref.cusName);
}

int Account::GetAccID() const { return accId; }

void Account::Deposit(int money)
{
    balance+=money;
}

int Account::Withdraw(int money)
{
    if(balance<money)
        return 0;

    balance -= money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout<<"Account ID: "<<accId<<endl;
    cout<<"name: "<<cusName<<endl;
    cout<<"balance: "<<balance<<endl;
}

Account::~Account()
{
    delete[] cusName;
}


