/*Write a C program to input two integers R, C,
representing the rows and columns of a 2D array. Next,
input R lines. Each line will have C integers. Finally, print
the maximum number of each row.*/

#include <stdio.h>

int main() {
    int R,C;
    scanf("%i%i",&R,&C);
    
    int max = 0,a;
    while(R--){
        for(int i=0;i<C;i++){
        scanf("%i",&a);
        if(a>max) 
        max =a;
    }
    printf("%i \n",max);

    }
    
    return 0;
}
