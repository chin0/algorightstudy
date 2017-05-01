#ifndef _BANK_H
#define _BANK_H

namespace Bank_Funcs
{
    enum {JOIN,DEPOSIT,WITHDRAW,PRINTMEM};
}

class account
{
private:
    int id;
    int money;
    char *name;
public:
    account(int id, int money, char *name);
    void withdraw(int money);
    int deposit(int money);
    void printInformation();
    int getId();
    ~account();
};


#endif
