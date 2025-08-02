#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void SelectionSort(vector<int> &arr){
    for(int i = 0 ; i < arr.size(); i++){
        int mn = i;
        for(int j = i+1 ; j < arr.size(); j++){
            if(arr[j] < arr[mn]){
                mn = j;
            }
        }
        swap(arr[i], arr[mn]);
    }
}


int main(){
    vector<int>arr(5);
    for(int i = 0;i<5;i++){
        cin>>arr[i];
    }
    SelectionSort(arr);
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}