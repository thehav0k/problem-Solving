#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cout << "Enter Fibonacci sequence number to print til : " << endl;
    cin >> n;

    cout << "Fibonacci sequence till " << n << " is : ";
    for (int i = 1; i <= n; i++)
    {
        cout << fib(i) << " ";
    }
    cout << endl;

    return 0;
}