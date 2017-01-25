#include <iostream>
#include <list>
#include <stack>

bool compare(int i,int j){ return (i>j); }
using namespace std;
int main(void)
{ 
    int n,tmp;
    stack<int> st;
    list<int> v;
    list<int> v2;
    list<char> result;

    cin >> n;
    for(int i = 0;i<n;i++){
       cin >> tmp;
       v.push_back(tmp);
       v2.push_back(tmp);
    }
    v.sort(compare);
    result.push_back('+');
    st.push(v.back());
    v.pop_back();
    while(!v.empty())
    {
        while(st.top() != v2.front())
        {
            if(v.empty()){
                cout << "NO\n";
                return 0;
            }

            result.push_back('+');
            st.push(v.back());
            v.pop_back();
        }
        while(!v.empty() && st.top() == v2.front()){
            result.push_back('-');
            st.pop();
            v2.pop_front();
        } 
    }
    while(!st.empty())
    {
        if(st.top() != v2.front()){
            cout << "NO\n";
            return 0;
        }
        result.push_back('-');
        st.pop();
        v2.pop_front();
    }
    list<char>::iterator i;
    for(i = result.begin();i!=result.end();i++){
        cout << *i << "\n";
    }
}

    
