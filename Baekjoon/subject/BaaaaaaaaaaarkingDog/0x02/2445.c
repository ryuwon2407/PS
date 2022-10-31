/**
 * @file 2445.c
 * @brief 2445. 별 찍기 - 8
 * @date 2022-10-31
 * 
 * @text 처음, 중간, 끝 세 파트로 나눠서 출력.
 * 
 */
#include <stdio.h>

#define ABS(x) (((x)<0) ? -(x) : (x))

int main()
{
    int N;

    scanf("%d", &N);
    for(int i = 1; i <= N * 2; i++)
    {
        for(int j = 1; j <= N - ABS(N - i); j++)
            printf("*");
        for(int j = 1; j <= ABS(N * 2 - i * 2); j++)
            printf(" ");
        for(int j = 1; j <= N - ABS(N - i); j++)
            printf("*");
        if(i != N * 2 - 1)
            printf("\n");
    }

    return 0;
}