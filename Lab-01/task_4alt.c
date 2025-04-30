/*Write a C program to input two integers M, N,
representing the number of elements in the arrays. Then
input M sorted integers and store them in an array named
arr, and input N sorted integers and store them in an
array named brr. Finally, merge the elements of both
arrays in sorted order into array named crr and print crr.*/

#include <stdio.h>

void store(int n,int a[]){
    for(int i=0;i < n ; i++){
        scanf("%i",&a[i]);
    }
}

int main() {
    int a,b;
    scanf("%i%i",&a,&b);
    int n=a+b;
    int arr[a],brr[b],crr[n];

    store(a,arr);
    store(b,brr);

    int i=0,j=0,k=0,c=n;
    while(c--)
    {
        if(i >= a) {  
           crr[k]= brr[j];
           k++;
           j++;
        }
        else if(j>= b) { 
           crr[k]= arr[i];
           k++;
           i++;
        }
        else if(arr[i]<brr[j])
        {
           crr[k]= arr[i];
           k++;
           i++;
        }
        else
        {
           crr[k]=brr[j];
           k++;
           j++;
        }
    }
    for(int x = 0;x<n;x++)
    {
        printf("%d ",crr[x]);
    }

    return 0;
}