#include <stdio.h>

int main()
{
    int k[7]         // 자연수 배열 k
    ,   odd_sum = 0  // 홀수 합
    ,   odd_min = 99;// 홀수 최소 값

    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &k[i]);
        if (k[i] % 2 == 1)
        {
            if (odd_min > k[i])
                odd_min = k[i];
            odd_sum += k[i];
        }
    }

    if (odd_sum != 0)
        printf("%d\n%d\n", odd_sum, odd_min);
    else
        printf("-1\n");
    
    return (0);
}