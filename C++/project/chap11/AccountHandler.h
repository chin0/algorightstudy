//
// Created by kafuuchin0 on 04.06.17.
//

#ifndef CHAP9_ACCOUNTHANDLER_H
#define CHAP9_ACCOUNTHANDLER_H

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
    AccountArray accArr;
    int accNum;
public:
    AccountHandler();
    void ShowMenu() const;
    void MakeAccount();
    void DepositMoney();
    void WithdrawMoney();
    void ShowAllAccInfo(void) const;
    ~AccountHandler();

protected:
    void MakeNormalAccount(void);
    void MakeCreditAccount(void);
};


#endif //CHAP9_ACCOUNTHANDLER_H
