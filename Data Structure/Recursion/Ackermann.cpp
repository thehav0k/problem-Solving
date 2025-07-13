#include<iostream>
using namespace std;

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m == 1) {
        return n + 2;
    } else if (m == 2) {
        return 2 * n + 3;
    } else if (m == 3) {
        return (1 << (n + 3)) - 3; // equivalent to pow(2, n + 3) - 3
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    int m, n;
    cout << "Enter values for m and n: ";
    cin >> m >> n;

    int result = ackermann(m, n);
    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;

    return 0;
}