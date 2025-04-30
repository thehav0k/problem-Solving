#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

bool isVowel(char a)
{
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
    return true;
    else
    return false;
}

int main()
{
    int n,k;
    cin >>n>>k;
    string a;
    cin>>a;
    for(int i=0;i<n;i++)
    a[i]=tolower(a[i]);
        
       int vow=0;
        for(int i=0;i<k;i++)
        {
            if(isVowel(a[i]))
            {
                vow++;
            }
        }
        int maxvow = vow;
        for(int i=0;i<n-k;i++)
        {
            if(isVowel(a[i])) vow--;
            if(isVowel(a[i+k])) vow++;
            maxvow = max(maxvow,vow);
        }
        cout<<maxvow<<endl;
    return 0;
}
