#include<iostream>
using namespace std;

int Euclidean_GCD(int a,int b)
{
    while(a>0 && b>0)
    {
        if(a>b) a%=b;
        else b%=a;
    }
    return (a==0 ? b : a);
}

int LCM(int a, int b){
    return (a / Euclidean_GCD(a,b)) * b;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<"GCD: "<<Euclidean_GCD(a,b)<<" LCM: "<<LCM(a,b)<<endl;
}