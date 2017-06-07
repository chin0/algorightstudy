//
// Created by kafuuchin0 on 04.06.17.
//

#ifndef CHAP9_NORMALACCOUNT_H
#define CHAP9_NORMALACCOUNT_H

#include "Account.h"

class NormalAccount : public Account
{
private:
    int interRate;
public:
    NormalAccount(int ID, int money, char *name, int rate)
            : Account(ID,money,name), interRate(rate)
    { }
    virtual void Deposit(int money)
    {
        Account::Deposit(money);
        Account::Deposit(money*(interRate/100.0));
    }
};


#endif //CHAP9_NORMALACCOUNT_H
