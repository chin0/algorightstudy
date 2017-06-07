//
// Created by kafuuchin0 on 04.06.17.
//

#ifndef CHAP9_ACCOUNT_H
#define CHAP9_ACCOUNT_H


class Account {
private:
    int accId;
    int balance;
    char *cusName;
public:
    Account(int ID, int money, char *name);
    Account(const Account &ref);

    int GetAccID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};


#endif //CHAP9_ACCOUNT_H
