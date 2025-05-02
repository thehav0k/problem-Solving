#include<iostream>
using namespace std;

long long RevNum(long long n){
    long long rev = 0,last_digit;
    while(n>0)
    {
        last_digit=n%10;
        rev = rev*10+last_digit;
        n/=10;
    }
    return rev;
}

bool isPallindrome(long long n)
{
    return n==RevNum(n);
}

bool isArmstrong(long long n)
{
    long long m=n,last_digit,Cube_sum=0;
    while(n>0)
    {
        last_digit = n%10;
        Cube_sum+= last_digit*last_digit*last_digit;
        n/=10;
    }
    return m==Cube_sum;
}

int main()
{
    long long n;
    cin>>n;
    cout<<"Reversed Number:"<<RevNum(n)<<endl;
    cout<<(isPallindrome(n) ? "Pallindrome" : "Non Pallindrome")<<endl;
    cout<<(isArmstrong(n) ? "Armstrong" : "Not Armstrong")<<endl;

return 0;
}