#include <stdio.h>

int main()
{
    int N; // 입력 N

    scanf("%d", &N);
    while (N--)
    {
        for (int i = 0; i <= N; i++)
            printf("*");
        printf("\n");
    }

    return (0);
}