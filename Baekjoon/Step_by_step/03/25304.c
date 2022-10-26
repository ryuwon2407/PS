/**
 * @file 25304.c
 * @brief 25304. 영수증
 * @date 2022-10-26
 * 
 * @text 단순 연산 (문자를 전부 대문자로 적어서 틀렸었음.)
 * 
 */

#include <stdio.h>

int main()
{
    int X       // 일치해야 할 총 금액
    ,   N       // 물건의 종류 수
    ,   a       // 물건의 가격
    ,   b       // 물건의 개수
    ,   sum = 0;// 총 합

    scanf("%d\n%d", &X, &N);
    while(N--)
    {
        scanf("%d %d", &a, &b);
        sum += a * b;
    }

    printf("%s\n", X == sum ? "Yes" : "No");
    return 0;
}