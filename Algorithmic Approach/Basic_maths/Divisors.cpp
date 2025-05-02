#include<iostream>
using namespace std;


void print_divisors(long long n)//Will iterate till n/2
{
    for(long long i=1;i<=n/2;i++)
    {
        if(!(n%i)) cout<<i<<" ";
    }
    cout<<n<<endl;
}

void print_divisors_optimized(long long n)
{
    for(long long i=1;i*i<=n;i++)//Will iterate till squareroot of n
    {
        if(!(n%i)) {cout<<i<<" ";
        if(n/i!=i) cout<<n/i<<" ";}
    }
    cout<<endl;
}

int main()
{
    long long n;
    cin>>n;
    print_divisors(n);
    print_divisors_optimized(n);

}