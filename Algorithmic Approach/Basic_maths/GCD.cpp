#include<iostream>
using namespace std;

int GCD(int n,int m)
{
    int limit = min(n,m);
    int i =1,gcd=1;
    while(i<=limit)
    {
        if(n%i==0 && m%i==0)
        {
            gcd =i;
        }
        i++;
    }
    return gcd;
}

int GCD_alt(int n,int m)
{
    int limit = min(n,m);
    for(int i = limit;i>=1;i--)
    {
        if(n%i==0 && m%i==0)
        {
            return i;
        }
    }
}

int Euclidean_GCD(int a,int b)
{
    while(a>0 && b>0)
    {
        if(a>b) a%=b;
        else b%=a;
    }
    return (a==0 ? b : a);
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<"Result from normal approach: "<<GCD(n,m)<<endl;
    cout<<"Result from alternative normal approach: "<<GCD_alt(n,m)<<endl;
    cout<<"Result from Euclidean approach: "<<Euclidean_GCD(n,m)<<endl;

    return 0;
}
