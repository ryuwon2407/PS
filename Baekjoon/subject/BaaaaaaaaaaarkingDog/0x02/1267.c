/**
 * @file 1267.c
 * @brief 1267. 핸드폰 요금
 * @date 2022-10-31
 * 
 * @text .
 * 
 */
#include <stdio.h>

#define CALL_MAX 10001
#define M_PRICE  15
#define Y_PRICE  10
#define M_TIME   60
#define Y_TIME   30

int call[CALL_MAX];

int main()
{
    int N
    ,   M_price_sum = 0
    ,   Y_price_sum = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &call[i]);
        Y_price_sum += Y_PRICE * (call[i] / Y_TIME + 1);
        M_price_sum += M_PRICE * (call[i] / M_TIME + 1);
    }

    if(Y_price_sum != M_price_sum)
        printf("%s %d\n", Y_price_sum < M_price_sum ? "Y" : "M", Y_price_sum < M_price_sum ? Y_price_sum : M_price_sum);
    else
        printf("%s %d\n", "Y M", Y_price_sum);

    return 0;
}