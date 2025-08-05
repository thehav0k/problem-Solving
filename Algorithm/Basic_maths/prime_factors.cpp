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

vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    return factors;
}

int main(){
    int n;
    cin>>n;
    cout<<"prime factors : "<<endl;
    vector<int> factors = primeFactors(n);

    for(auto i:factors) cout<<i<<" ";
    cout<<endl;
}