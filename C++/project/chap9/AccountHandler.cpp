//
// Created by kafuuchin0 on 04.06.17.
//
#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

void AccountHandler::ShowMenu() const
{
    cout<<"-----Menu-----"<<endl;
    cout<<"1. create account."<<endl;
    cout<<"2. withdraw."<<endl;
    cout<<"3. deposit."<<endl;
    cout<<"4. print account information."<<endl;
    cout<<"5. quit."<<endl;
}

void AccountHandler::MakeAccount()
{
    int sel;
    cout<<"[select account]"<<endl;
    cout<<"1. normal account."<<endl;
    cout<<"2. high credit account."<<endl;
    cout<<"select: "; cin>>sel;

    if(sel==NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;

    cout<<"[create normal account]"<<endl;
    cout<<"account id: "; cin>>id;
    cout<<"name: "; cin>>name;
    cout<<"balance: "; cin>>balance;
    cout<<"interest rate: "; cin>>interRate;
    cout<<endl;
    accArr[accNum++] = new NormalAccount(id,balance,name,interRate);
}

void AccountHandler::MakeCreditAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;
    int creditLevel;

    cout<<"[create normal account]"<<endl;
    cout<<"account id: "; cin>>id;
    cout<<"name: "; cin>>name;
    cout<<"balance: "; cin>>balance;
    cout<<"interest rate: "; cin>>interRate;
    cout<<"credit level: "; cin>>creditLevel;
    cout<<endl;

    switch(creditLevel){
        case 1:
            accArr[accNum++] = new HighCreditAccount(id,balance,name,interRate,LEVEL_A);
            break;
        case 2:
            accArr[accNum++] = new HighCreditAccount(id,balance,name,interRate,LEVEL_B);
            break;
        case 3:
            accArr[accNum++] = new HighCreditAccount(id,balance,name,interRate,LEVEL_C);
            break;
        default:
            accArr[accNum++] = new HighCreditAccount(id,balance,name,interRate,LEVEL_A);
            break;
    }
}

void AccountHandler::DepositMoney()
{
    int money;
    int id;
    cout<<"[deposit money]"<<endl;
    cout<<"account id: "; cin >> id;
    cout<<"money: "; cin >> money;

    for(int i = 0; i < accNum; i++){
        if(accArr[i]->GetAccID()==id){
            accArr[i]->Deposit(money);
            cout<<"complete."<<endl;
            return;
        }
    }
    cout<<"invalid id."<<endl<<endl;
}

void AccountHandler::WithdrawMoney()
{
    int money;
    int id;
    cout<<"[withdraw money]"<<endl;
    cout<<"account id: "; cin >> id;
    cout<<"money: "; cin >> money;

    for(int i = 0; i < accNum; i++){
        if(accArr[i]->Withdraw(money)==0){
            cout<<"fail."<<endl<<endl;
            return;
        }
        cout<<"done."<<endl<<endl;
        return;
    }
    cout<<"invalid id."<<endl<<endl;
}

AccountHandler::AccountHandler() : accNum(0)
{}

void AccountHandler::ShowAllAccInfo() const
{
    for(int i = 0; i < accNum; i++){
        accArr[i]->ShowAccInfo();
        cout<<endl;
    }
}

AccountHandler::~AccountHandler()
{
    for(int i = 0; i < accNum; i++)
        delete accArr[i];
}