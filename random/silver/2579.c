#include <stdio.h>

#define MAX 300

int dp[MAX];

int main()
{
    int N
    ,   s[MAX];

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &s[i]);

    //초기값 세팅
    dp[0] = s[0];
    dp[1] = s[0] + s[1] > s[1] ? s[0] + s[1] : s[1];
    dp[2] = s[0] + s[2] > s[1] + s[2] ? s[0] + s[2] : s[1] + s[2];

    for(int i = 2; i < N; i++)
        dp[i] = dp[i - 2] + s[i] > dp[i - 3] + s[i] + s[i - 1] ? dp[i - 2] + s[i] : dp[i - 3] + s[i] + s[i - 1] ;
    
    printf("%d", dp[N - 1]);

    return (0);
}