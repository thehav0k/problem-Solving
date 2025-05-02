#include<iostream>
using namespace std;

bool isArmstrong(long long n)
{
    long long m=n,last_digit,Cube_sum=0; /*Assigning number n to m
     to conserve the value bcz n is gonna update in the loop*/
    while(n>0)
    {
        last_digit = n%10;
        Cube_sum+= last_digit*last_digit*last_digit;
        n/=10;
    }
    return m==Cube_sum;
}

int main(){
    long long n;
    cin>>n;
    cout<<(isArmstrong(n) ? "Armstrong" : "Not Armstrong")<<endl;
    return 0;
}