#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
    char *name;
    int age;
public:
    MyFriendInfo(char *str, int age) 
      : age(age)
    {
        name = new char[strlen(name) + 1];
        strcpy(name,str);
    }
    void ShowMyFriendInfo()
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char *addr;
    char *phone;

public:
    MyFriendDetailInfo(char *str, int age, char *address, char *phone_num)
        : MyFriendInfo(str,age)
    {
        addr = new char[strlen(address) + 1];
        phone = new char[strlen(phone_num) + 1];
        strcpy(addr,address);
        strcpy(phone,phone_num);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout<<"주소: "<<addr<<endl;
        cout<<"전화: "<<phone<<endl<<endl;
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
};

int main(void)
{
    MyFriendDetailInfo chino("chino",16,"strasbourg","010-2212-1231");
    chino.ShowMyFriendDetailInfo();
}

