#include <stdio.h>

#define MAX 31

int dp[MAX][MAX];

int main()
{
    int N
    ,   K;

    for (int i = 1; i < MAX; i++)
        for (int j = 1; j <= i; j++)
            if (j == 1 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    
    scanf("%d %d", &N, &K);
    printf("%d\n", dp[N][K]);

    return (0);
}