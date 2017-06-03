#include <iostream>
#include <cstring>

using namespace std;

class Girl; //Girl 클래스가 있다는것을 먼저 명시한다.

//friend선언은 private,protected,public중 아무데나 있어도 상관없다.

class Boy
{
private:
    int height;
    friend class Girl; //Girl 클래스를 대상으로 friend선언(Girl은 Boy의 private멤버에 접근가능.)
public:
    Boy(int len) : height(len)
    { }
    void ShowYourFriendInfo(Girl &frn);
};

class Girl
{
private:
    char phNum[20];
public:
    Girl(char *num)
    {
        strcpy(phNum,num);
    }
    void ShowYourFriendInfo(Boy &frn);
    friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &frn)
{
    cout<<"Her phone number: "<< frn.phNum<<endl;
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
    cout<<"His height: "<<frn.height<<endl;
}

int main(void)
{
    Boy boy(170);
    Girl girl("010-1231-1231");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
    return 0;
}


