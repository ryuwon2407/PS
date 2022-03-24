#include <stdio.h>

int main()
{
    int ascending   = 0
    ,   descending  = 0;
    int i, num[8];

    scanf("%d %d %d %d %d %d %d %d", 
    &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7]);

    for(i = 0; i < 7; i++)
    {
        if(num[i] <= num[i + 1])
            ascending++;
        if(num[i] >= num[i + 1])
            descending++;
    }

    if(ascending == i)
        printf("ascending\n");
    else if(descending == i)
        printf("descending\n");
    else
        printf("mixed\n");
    
    return (0);
}