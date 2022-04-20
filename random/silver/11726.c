#include <stdio.h>

#define MAX 1001

int dp[MAX];

int main()
{
    int N;

    dp[1] = 1, dp[2] = 2;
    for(int i = 3; i < MAX; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

    scanf("%d", &N);
    printf("%d\n", dp[N]);

    return (0);
}

// 1 1 1
// 1 --
// -- 1

// 1 1 1 1
// 1 1 --
// 1 -- 1
// -- 1 1
// -- --

// 1 1 1 1 1
// -- 1 1 1
// 1 -- 1 1
// 1 1 -- 1
// 1 1 1 --
// -- 1 --
// 1 -- --
// -- -- 1