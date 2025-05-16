/*
Write a C program to input two integer variables. Then
create a function to swap the two numbers using pointers.
Prints the numbers before and after the swap.
*/
#include<stdio.h>

void swap(int* a, int* b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("%d %d\n",a,b);
  
    return 0;
}