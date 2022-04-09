#include <stdio.h>

int main()
{
    int N;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int start = 0; start < i; start++)
            printf(" ");
        for(int mid = (N - i) * 2 - 1 ; mid > 0; mid--)
            printf("*");
        printf("\n");
    }

    return (0);
}