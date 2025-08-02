#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void BubbleSort(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 1;j<arr.size()-i;j++){
            if(arr[j]<arr[j-1]){
                swap(arr[j-1],arr[j]);
            }
        }
    }
}


int main(){
    vector<int>arr(5);
    for(int i = 0;i<5;i++){
        cin>>arr[i];
    }
    BubbleSort(arr);
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}