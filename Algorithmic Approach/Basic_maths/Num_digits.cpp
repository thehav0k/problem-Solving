#include<iostream>
#include<cmath>
using namespace std;

//using log10 --> Direct answer(Checks power of 10)
// must need cmath library
int count_digits(long long n)
{
    return log10(n)+1;
}

// Using Loop --> counting how many times n can be divided by 10
int count_digits_(long long n){
    int count=0;
    while(n>0){
        count++;
        n/=10;
    }
    return count;
}

int main(){
    long long n;
    cin>>n;
    cout<<count_digits(n)<<endl;
    cout<<count_digits_(n)<<endl;

    return 0;
}
