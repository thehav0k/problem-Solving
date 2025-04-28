#include<iostream>
using namespace std;

bool isPrime(int n)
{
    bool prime = true;
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            prime = false;
            break;
        }
    }
    return prime;
}

int main(){
    int n;
    while(cin>>n){
         cout<<(isPrime(n)? "Prime Number": "Composite Number")<<endl;
    }
    return 0;
}
