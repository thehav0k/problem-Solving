#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for (int i = 0; i<n;i++)
        cin >> a[i];
        
       int sum=0,maxsum;
        for(int i=0;i<k;i++)
        {
            sum+=a[i];
        }
        maxsum = sum;
        for(int i=0;i<n-k;i++)
        {
            sum-=a[i];
            sum+=a[i+k];
            maxsum =max(maxsum,sum);
        }
        cout<<maxsum<<endl;
  return 0;
    
}
