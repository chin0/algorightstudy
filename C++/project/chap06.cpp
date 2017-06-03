#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

enum {MAKE=1,DEPOSIT,WITHDRAW,INQUIRE,EXIT};
namespace HIGHCREDIT
{
    enum {A_RATE=7, B_RATE=4, C_RATE=2};
}
    

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
    virtual void Deposit(int money);
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

class NormalAccount : public Account
{
private:
    int interest;
public:
    NormalAccount(int ID, int money, char *name, int interest)
        : Account(ID,money,name), interest(interest)
    { }
    virtual void Deposit(int money)
    {
        Account::Deposit(money);
        Account::Deposit(money * (interest/100.0));
    }
};

class HighCreditAccount : public NormalAccount
{
private:
    int credit_rate;
public:
    HighCreditAccount(int ID,int money, char *name, int interest, int credit_rate)
        : NormalAccount(ID,money,name,interest), credit_rate(credit_rate)
    { }
    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money);
        Account::Deposit(money * (credit_rate/100.0));
    }
};
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
    int select;
    int interest;
    char credit_rate;

    cout<<"[Select Account]"<<endl;
    cout<<"1.Normal account 2.High credit account"<<endl;
    cout<<"select: "; cin >> select;
    if(select==1){
        cout<<"[Create Normal Account]"<<endl;
        cout<<"Account ID: "; cin>>id;
        cout<<"name: "; cin>>name;
        cout<<"money: "; cin>>balance;
        cout<<"interest: "; cin>>interest;
        cout<<endl;

        accArr[accNum++]=new NormalAccount(id,balance,name,interest);
    } else if(select==2){
        cout<<"[Create Normal Account]"<<endl;
        cout<<"Account ID: "; cin>>id;
        cout<<"name: "; cin>>name;
        cout<<"money: "; cin>>balance;
        cout<<"interest: "; cin>>interest;
        cout<<"credit rate: "; cin>>credit_rate;
        cout<<endl;

        switch(credit_rate){
            case 'A':
                accArr[accNum++]=new HighCreditAccount(id,balance,name,interest,HIGHCREDIT::A_RATE);
                break;
            case 'B':
                accArr[accNum++]=new HighCreditAccount(id,balance,name,interest,HIGHCREDIT::B_RATE);
                break;
            case 'C':
                accArr[accNum++]=new HighCreditAccount(id,balance,name,interest,HIGHCREDIT::C_RATE);
                break;
        }
    } else {
        cout << "wrong select.." << endl;
        return;
    }
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

