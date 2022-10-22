#include <stdio.h>

#define MAX 100
#define NUM_MAX 1000000000

int main()
{
    int N
    ,   min = NUM_MAX
    ,   num[MAX]
    ,   remain[MAX];

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        if(min > num[i])
            min = num[i];
    }

    for(int i = 0; i <= min; i++)
    {
        for()
    }
    
    
}