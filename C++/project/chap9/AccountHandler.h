//
// Created by kafuuchin0 on 04.06.17.
//

#ifndef CHAP9_ACCOUNTHANDLER_H
#define CHAP9_ACCOUNTHANDLER_H

#include "Account.h"

class AccountHandler
{
private:
    Account *accArr[100];
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
