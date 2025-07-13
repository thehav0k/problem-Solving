#include <iostream>
using namespace std;

int arrSum(int arr[],int n){
    if(n==1)
    return arr[n-1];

    return arr[n-1] + arrSum(arr,n-1);
}

int main()
{
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of the array: ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    
    int result = arrSum(arr, n);
    cout << "The sum of the array elements is: " << result << endl;
    
    return 0;
}