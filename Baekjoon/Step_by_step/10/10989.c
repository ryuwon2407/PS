/**
 * @file 10989.c
 * @brief 10989. 수 정렬하기 3
 * @date 2022-11-19
 * 
 * @text 카운팅 정렬을 사용하여 수 정렬
 * 
 */
#include <stdio.h>

#define MAX 10001

int num[MAX];

int main()
{
    int N
    ,   temp;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        num[temp]++;
    }

    for(int i = 1; i <= MAX; i++)
        for(int j = 0; j < num[i]; j++)
            printf("%d\n", i);
    
    return 0;
}