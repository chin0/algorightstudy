#include <iostream>
#include <vector>
#include <stack>

#define INFINITY 2147438647 
using namespace std;

vector<vector<int> > list;

int main(void)
{
    int i,count,temp,start,end;
    vector<int> visited,S,priv;

    cout << "n: ";
    cin >> count;
    vector<int> dn(count,INFINITY);

    for(i = 0; i < count; i++)
    {
        vector<int> tempvec(count,0);
        list.push_back(tempvec);
        visited.push_back(i);
    }

    for(i = 0; i < count; i++)
    {
        for(int j = 0; j < count; j++)
            cin >> list[i][j];
    }
    
    cin >> start >> end;
    dn[start] = 0;
    int min;
    while(!visited.empty())
    {
        min = visited[0];
        for(i = 0; i < visited.size(); i++){
            min = (dn[min] > dn[visited[i]]) ? visited[i] : min;
        }
        for(i = 0; i< visited.size(); i++)
        {
            if(visited[i] == min){
                visited.erase(visited.begin() + i);
                break;
            }
        }
        S.push_back(min);

        for(i = 0; i<count; i++)
        {
            if(list[min][i] != 0)
            {
                int dis = dn[min] + list[min][i];
                if(dn[i] > dis)
                {
                    dn[i] = dis;
                    priv.push_back(min);
                }
            }
        }
    }

    for(i = 0; i < dn.size(); i++){
        cout << start << "와 " << i << "정점 사이의 최단 거리" << dn[i] << endl;
    }
    cout << "\n";
    for(i = 0; i < count; i++){
        cout << priv[i] << " ";
    }
    cout << "\n";

}
        
     
