#include <iostream>
using namespace std;

int sum(int n)
{
    if (n <= 0) // base case
        return 0;
    return n + sum(n - 1);
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int result = sum(n);
    cout << "The sum of all integers from 1 to " << n << " is: " << result << endl;

    return 0;
}