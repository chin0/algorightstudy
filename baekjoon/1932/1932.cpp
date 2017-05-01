#include <iostream>

using namespace std;

int n,map[500][500],ret[500][500];

int solve()
{
    int max = 0;
    ret[0][0] = map[0][0];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(ret[i+1][j] < map[i+1][j] + ret[i][j])
                ret[i+1][j] = map[i+1][j] + ret[i][j];
            if(ret[i+1][j+1] < map[i+1][j+1] + ret[i][j])
                ret[i+1][j+1] = map[i+1][j+1] + ret[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        if(max < ret[n-1][i])
            max = ret[n-1][i];
    }
    return max;
}
            

    
int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            cin >> map[i][j];
    }
    cout << solve() << endl;
}


    
