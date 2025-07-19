#include<iostream>
using namespace std;

void moveDisk(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << fromRod << " to rod " << toRod << endl;
        return;
    }
    moveDisk(n - 1, fromRod, auxRod, toRod);
    cout << "Move disk " << n << " from rod " << fromRod << " to rod " << toRod << endl;
    moveDisk(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;

    moveDisk(n, 'A', 'C', 'B'); // A, B and C are names of rods

    return 0;
}