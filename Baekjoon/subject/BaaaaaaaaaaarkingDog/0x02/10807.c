#include <stdio.h>

#define MAX 202

int num[MAX];

int main()
{
    int N
    ,   temp;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&temp);
        num[temp+100]++;
    }
    
    scanf("%d",&temp);
    printf("%d\n",num[temp+100]);

    return (0);
}