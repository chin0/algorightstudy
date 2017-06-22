#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage)
    {
        int len=strlen(myname+1);
        name=new char[len];
        strcpy(name,myname);
        age=myage;
    }
    void ShowPersonInfo() const
    {
        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
    }
    Person& operator=(const Person& ref)
    {
        delete []name;
        int len=strlen(ref.name);
        name=new char[len];
        strcpy(name,ref.name);
        return *this;
    }
    ~Person()
    {
        delete []name;
        cout<<"Called destructor!"<<endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);
    man2=man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}
    
