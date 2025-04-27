/*Write a C program to input two integers M, N,
representing the number of elements in the arrays. Then
input M sorted integers and store them in an array named
arr, and input N sorted integers and store them in an
array named brr. Finally, merge the elements of both
arrays in sorted order into array named crr and print crr.*/

#include <stdio.h>

void bubble_sort(int n,int a[])
{
    for(int i=0;i < n-1 ; i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i < n ; i++)
        printf("%i ",a[i]);
}

void store(int n,int a[]){
    for(int i=0;i < n ; i++){
        scanf("%i",&a[i]);
    }
}

int main() {
    int a,b,c;
    scanf("%i%i",&a,&b);
    c=a+b;
    int arr[a],brr[b],crr[c];

    store(a,arr);
    store(b,brr);
    int pos=0;
    for(int i=0;i<a;i++)
        crr[pos++]=arr[i];
    for(int j=0;j<b;j++)
        crr[pos++]=brr[j];
    bubble_sort(c,crr);

    return 0;
}
