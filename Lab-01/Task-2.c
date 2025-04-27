/*Given an odd integer N, print a rectangle in the following
format, if N=9 .*/

#include <stdio.h>

int main() {
    int n;
    scanf("%i",&n);
    int k =n;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j || j==1 ||j==k || i==1 || i==n||j==n)
            printf("@");
            else
            printf(" ");

        }
        k--;
        printf("\n");
    }
    
    return 0;
}
