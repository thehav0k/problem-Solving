#include<iostream>
#include<vector>
#define LIMIT 10000000
using namespace std;

vector<bool> Sieve(LIMIT+1,true);

void isPrime()
{
    Sieve[0] = false;
    Sieve[1] = false;
    for (int i = 2; i * i <= LIMIT; i++) {
        if (Sieve[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                Sieve[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    isPrime();
    while(cin >> n)
    {
        cout << (Sieve[n] ? "Prime" : "Composite") << endl;
    }
    return 0;
}
