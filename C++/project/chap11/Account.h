//
// Created by kafuuchin0 on 04.06.17.
//

#ifndef CHAP9_ACCOUNT_H
#define CHAP9_ACCOUNT_H

#include "string.h"

class Account {
private:
    int accId;
    int balance;
    String cusName;
public:
    Account(int ID, int money, String name);
    Account(const Account &ref);

    int GetAccID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
};


#endif //CHAP9_ACCOUNT_H
