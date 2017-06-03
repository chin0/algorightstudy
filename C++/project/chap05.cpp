#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

enum {MAKE=1,DEPOSIT,WITHDRAW,INQUIRE,EXIT};

//Entity class
class Account
{
private:
    int accID;
    int balance;
    char *cusName;
public:
    Account(int ID,int money, char *name);
    Account(const Account &ref);

    int GetAccID() const;
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};

Account::Account(int ID, int money, char *name)
    : accID(ID), balance(money)
{
    cusName=new char[strlen(name)+1];
    strcpy(cusName, name);
}

Account::Account(const Account &ref)
    : accID(ref.accID), balance(ref.balance)
{
    cusName=new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money)
{
    balance+=money;
}

int Account::Withdraw(int money)
{
    if(balance<money)
        return 0;
    balance-=money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout<<"AccountID: "<<accID<<endl;
    cout<<"Name: "<<cusName<<endl;
    cout<<"Balance: "<<balance<<endl;
}

Account::~Account()
{
    delete []cusName;
}

//control class
class AccountHandler
{
private:
    Account *accArr[100];
    int accNum;
public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    ~AccountHandler();
};

void AccountHandler::ShowMenu(void) const
{
    cout<<"-----Menu-----"<<endl;
    cout<<"1.Create Account"<<endl;
    cout<<"2.Deposit"<<endl;
    cout<<"3.Withdraw"<<endl;
    cout<<"4.Show all accounts.."<<endl;
    cout<<"5.exit"<<endl;
}

void AccountHandler::MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[Create Account]"<<endl;
    cout<<"Account ID: "; cin>>id;
    cout<<"name: "; cin>>name;
    cout<<"money: "; cin>>balance;
    cout<<endl;

    accArr[accNum++]=new Account(id,balance,name);
}

void AccountHandler::DepositMoney(void)
{
    int money;
    int id;
    cout<<"[Deposit Money]"<<endl;
    cout<<"Account ID: ";cin>>id;
    cout<<"money: "; cin>>money;

    for(int i=0; i<accNum; i++){
        if(accArr[i]->GetAccID()==id){
            accArr[i]->Deposit(money);
            cout<<"Complete."<<endl<<endl;
            return;
        }
    }
    cout << "ID not found."<<endl<<endl;
}

void AccountHandler::WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"[Withdraw Money]"<<endl;
    cout<<"Account ID: ";cin>>id;
    cout<<"money: ";cin>>money;

    for(int i = 0; i < accNum;i++){
        if(accArr[i]->GetAccID()==id){
            if(accArr[i]->Withdraw(money)==0)
            {
                cout<<"not enough money."<<endl;
                return;
            }
            cout<<"complete."<<endl<<endl;
        }
    }
    cout << "ID not found." << endl;
}

AccountHandler::AccountHandler() : accNum(0)
{ }

void AccountHandler::ShowAllAccInfo(void) const
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

int main(void)
{
    AccountHandler manager;
    int choice;

    while(1){
        manager.ShowMenu();
        cout<<"선택: ";
        cin>>choice;
        cout<<endl;

        switch(choice){
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout<<"Illegal selection.."<<endl;
        }
    }
    return 0;
}

