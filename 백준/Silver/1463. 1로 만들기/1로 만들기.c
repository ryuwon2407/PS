#include <stdio.h>

#define MAX 1000001

int dp[MAX];

int main()
{
    int N; // 정수 X

    scanf("%d", &N);
    dp[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            if(dp[i] > dp[i / 2] + 1)
                dp[i] = dp[i / 2] + 1;
        if(i % 3 == 0)
            if(dp[i] > dp[i / 3] + 1)
                dp[i] = dp[i / 3] + 1;
    }
    printf("%d\n", dp[N]);
    
    return (0);
}

// 1 2 3 4 5 6 7 8 9 10 11 12
// 0 1 1 2 3 2 3 3 3 4  5  3  