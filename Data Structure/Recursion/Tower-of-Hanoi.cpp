#include<iostream>
using namespace std;

void moveDisk(int n, char A, char C, char B) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << A << " to rod " << C << endl;
        return;
    }
    moveDisk(n - 1, A, B, C);
    cout << "Move disk " << n << " from rod " << A << " to rod " << C << endl;
    moveDisk(n - 1, B, C, A);
}

int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;

    moveDisk(n, 'A', 'C', 'B'); // A, B and C are names of rods

    return 0;
}