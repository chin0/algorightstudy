#include <iostream>
#include <vector>

typedef unsigned long long ull;

using namespace std;

ull get_tri_number(ull n)
{
    return (n * n + n) / 2;
}

int count_prime_number(ull tri_number)
{
    int result = 1;

    if(tri_number == 1)
        return -1;
    
    vector<int> prime_numbers;
    for(int i = 2; tri_number > 1; i++)
        while(tri_number % i == 0)
        {
            tri_number /= i;
            prime_numbers.push_back(i);
        }
    
    int a = prime_numbers[0];
    int count = 1;
    for(int i = 1; i < prime_numbers.size(); i++){
        if(a == prime_numbers[i])
            count++;
        else{
            result *= count + 1;
            a = prime_numbers[i];
            count = 1;
        }
    }
    result *= count + 1;
            
    
    return result;        
}

int main(void)
{
    ull n = 2;
    int count = 0;
    for(;;)
    {
        ull temp = get_tri_number(n);
        int prime_count = count_prime_number(temp);
        if(prime_count >= 500)
        {
            cout << temp << endl;
            break;
        }
        n++;
        count++;
    }
    cout << count << endl;
}


    

