#include <stdio.h>

int main()
{
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int space = N - i - 1; space > 0; space--)
            printf(" ");
        for(int star = (i * 2) + 1; star > 0; star--)
            printf("*");
        printf("\n");
    }

    return (0);
}