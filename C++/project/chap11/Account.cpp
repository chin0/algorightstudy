//
// Created by kafuuchin0 on 04.06.17.
//

#include "string.h"
#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, String name)
        : accId(ID), balance(money)
{
    cusName=name;
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


