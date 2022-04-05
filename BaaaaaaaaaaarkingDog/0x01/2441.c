#include <stdio.h>

int main()
{
    int N; //별의 갯수

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i; j++)
            printf(" ");
        for(int k = N - i; k > 0; k--)
            printf("*");
        printf("\n");
    }

    return (0);
}