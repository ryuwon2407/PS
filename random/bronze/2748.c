#include <stdio.h>

#define MAX 91

int main()
{
    long long int N
    ,   dp[MAX];

    dp[0] = 0, dp[1] = 1;

    scanf("%lld", &N);
    for(int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    printf("%lld\n", dp[N]);

    return (0);
}