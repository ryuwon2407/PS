#include <stdio.h>

#define MAX 1000001

unsigned long long dp[MAX]; // 0으로 초기화

int main()
{
    int testcase_num, num;

    for(int i = 1; i <= MAX; i++)
    {
        for(int j = i; j <= MAX; j += i)
            dp[j] += i;
        dp[i] += dp[i - 1];
    }

    scanf("%d", &testcase_num);
    for(int i = 0; i < testcase_num; i++)
    {
        scanf("%d", &num);
        printf("%lld\n", dp[num]);
    }

    return (0);
}

// g(1) = 1
// g(2) = 4
// g(3) = 8
// g(4) = 15

//dp
//1 1 1 1 1 1
//dp[1] += dp[0](0);
//  2   2   2
//dp[2] += dp[1](1);
//dp[2] == 4
//    3     3
//dp[3] += dp[2](4);
//dp[3] == 8