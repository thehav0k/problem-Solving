#include <iostream>
using namespace std;

int fact(int n)
{
    if (n < 2) // base case
        return n;
    return n * fact(n - 1);
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int result = fact(n);
    cout << "The factorial of " << n << " is: " << result << endl;

    return 0;
}