/*Write a C program that takes an integer 𝑁 as input, Then
print the frequency of its digits*/

#include <stdio.h>

int main() {
    long long n;
    scanf("%lld",&n);
    int a[10];
    for(int i=0;i<10;i++)
    {
        a[i]=0;
    }
    int rem;
    while(n!=0)
    {
        rem = n%10;
        a[rem]++;
        n/=10;
    }
    for(int i=0;i<10;i++)
    {
        printf("%i ",a[i]);
    }
    return 0;
}
