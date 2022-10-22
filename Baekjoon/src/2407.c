#include <stdio.h>

#define MAX 101

char* dp[MAX][MAX];

int main()
{
    int N
    ,   M;

    // 초기값 세팅
    dp[1][0] = '1';
    dp[1][1] = '1';
    
    for(int i = 2; i <= 100; i++)
    {
        for(int j = 0; j <= i; j++)
            if(dp[i][j] == 0)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }

    scanf("%d %d", &N, &M);
    printf("%llu", dp[N][M]);

    return (0);
}

//5C5 
//1
//6C5 6C6
//6   1
//7C5 7C6 7C7
//21  7   1
//8C5 8C6 8C7 8C8
//56  28  8   1

//5 15 25 
//6 21 

//unsigned long long int 형도 오버플로우
