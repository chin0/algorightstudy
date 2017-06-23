#include <iostream>

using namespace std;

struct FuncObject
{
public:
    void operator()(int arg) const{
        cout << "integer: " << arg << endl;
    }

    void operator()(int arg1, int arg2){
        cout << "integer: " << arg1 << ',' << arg2 << endl;
    }

    void operator()(int arg1, int arg2, int arg3){
        cout << "integer: " << arg1 << ',' << arg2 << ',' << arg3 << endl;
    }
};

int main()
{
    FuncObject print;
    print(10);
    print(10,20);
    print(10,20,30);
    
    cout << endl;

    print.operator()(10);
    print.operator()(10,20);
    print.operator()(10,20,30);
    cout << endl;

    FuncObject()(10); 
    FuncObject()(10,20,30);
    FuncObject()(10,20); 
    cout << endl;

    FuncObject().operator()(10);
    FuncObject().operator()(20,30);
    FuncObject().operator()(10,20,30);

    return 0;
}