#include <stdio.h>
#include <ctype.h>

int isVowel(char c)
{
    char t = tolower(c);
    if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
        return 1;
    return 0;
}

int main()
{
    char s[1000];
    fgets(s, 1000, stdin);
    char *t = s;
    while (*t != '\0')
    {
        if (isVowel(*t))
            printf("%c", *t);
        t++;
    }
    printf("\n");
}