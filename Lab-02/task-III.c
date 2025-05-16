#include<stdio.h>

int main()
{
    char s[1000];
    fgets(s,1000,stdin);
    char* t=s;
    
    int count=-1;
    while(*t!='\0')
    {
        t++;
        count++;
    }
    printf("%d\n",count);

    return 0;
}