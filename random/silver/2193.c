#include <stdio.h>

#define MAX 90 + 1

int main()
{
    unsigned long long int N
    ,   dp[MAX];

    dp[1] = 1, dp[2] = 1;

    scanf("%d", &N);
    for(int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    printf("%llu\n", dp[N]);
    
    return (0);
}

// 1 1
// 2 1
// 3 2
// 4 3
// 5 5
// 6 8

//1000, 1001, 1010
//10000, 10101, 10100, 10010, 10001
//100000, 101000, 101010, 101001, 100100, 100101, 100010, 100001