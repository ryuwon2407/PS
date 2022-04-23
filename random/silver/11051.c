#include <stdio.h>

#define MAX 1001

int dp[MAX][MAX];

int main()
{
    int N
    ,   K;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
    
    scanf("%d %d", &N, &K);
    printf("%d\n", dp[N][K]);

    return (0);
}

//      0C0
//    1C0 1C1 
//  2C0 2C1 2C2
//3C0 3C1 3C2 3C3

//       1
//     1   1
//   1   2   1
// 1   3   3   1

//nCk = n-1Ck-1 + n-1Ck
