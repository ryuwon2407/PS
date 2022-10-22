#include <stdio.h>

#define MAX 101

int main()
{
    char str[MAX];

    while(gets(str))
        printf("%s\n", str);
    
    return (0);
}