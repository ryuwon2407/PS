#include <stdio.h>

#define MAX 41

typedef struct s_fibonacci{
    int zero_count;
    int one_count;
}t_fibonacci;

int main()
{
    t_fibonacci dp[MAX];     //dp 
    int         temp         //피보나치 수
    ,           testcase_num;//testcase 수

    dp[0].zero_count = 1, dp[0].one_count = 0;
    dp[1].zero_count = 0, dp[1].one_count = 1;

    for(int i = 2; i < MAX; i++)
    {
        dp[i].zero_count = dp[i - 1].zero_count + dp[i - 2].zero_count;
        dp[i].one_count  = dp[i - 1].one_count  + dp[i - 2].one_count;
    }
    
    scanf("%d", &testcase_num);
    while(testcase_num--)
    {
        scanf("%d", &temp);
        printf("%d %d\n", dp[temp].zero_count, dp[temp].one_count);
    }

    return (0);
}

//0    1    2    3    4    5    6
//1 0  0 1  1 1  1 2  2 3  3 5  5 8