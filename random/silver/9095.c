#include <stdio.h>

#define MAX 11 + 1

int main()
{
    int N
    ,   dp[MAX]
    ,   testcase_num;
    
    // 더하기 연산 횟수
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for(int i = 4; i < MAX; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    scanf("%d", &testcase_num);
    while(testcase_num--)
    {
        scanf("%d", &N);
        printf("%d\n", dp[N]);
    }

    return (0);
}

// 1 1
// 2 2
// 3 4
// 4 7
// 5 13
// 6 24
// 7 44


// 1 1 1 1 1    
// 2 1 1 1      
// 1 2 1 1      
// 1 1 2 1
// 1 1 1 2
// 3 1 1
// 1 3 1
// 1 1 3
// 2 2 1
// 2 1 2
// 1 2 2
// 2 3
// 3 2