//
// Created by kafuuchin0 on 04.06.17.
//

#ifndef CHAP9_HIGHCREDITACCOUNT_H
#define CHAP9_HIGHCREDITACCOUNT_H

#include "NormalAccount.h"
#include "string.h"

class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;
public:
    HighCreditAccount(int ID, int money, String name, int rate, int special)
            : NormalAccount(ID,money,name,rate), specialRate(special)
    { }
    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money);
        Account::Deposit(money*(specialRate/100.0));
    }
};
#endif //CHAP9_HIGHCREDITACCOUNT_H
