#include <iostream>

using namespace std;

int n,houses[1000][3];

enum {R,G,B};

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int main(void)
{
    int rgb_min;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> houses[i][R] >> houses[i][G] >> houses[i][B];

    for(int i = 1; i < n; i++)
    {
        houses[i][R] = min(houses[i-1][G],houses[i-1][B]) + houses[i][R];
        houses[i][G] = min(houses[i-1][R],houses[i-1][B]) + houses[i][G];
        houses[i][B] = min(houses[i-1][G],houses[i-1][R]) + houses[i][B];
    }

    rgb_min = min(houses[n-1][R],houses[n-1][B]);
    rgb_min = min(rgb_min,houses[n-1][G]);

    cout << rgb_min << endl;

    return 0;
}

    
