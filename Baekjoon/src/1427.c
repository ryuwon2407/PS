/**
 * @file 1427.c
 * @brief 1427. 소트인사이드
 * @date 2022-11-16
 * 
 * @text qsort 내림차순 이용하여 정렬
 * 
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int num[10];

int descend(const void* a, const void* b){
    if(*(int *)a < *(int *)b)
        return -1;
    else if(*(int *)a > *(int *)b)
        return 1;
    else
        return 0;
}

int main()
{
    int N
    ,   len;

    scanf("%d", &N);
    for(len = 0; N != 0; len++){
       num[len] = N % 10;
       N /= 10;
    }

    qsort(num, len, sizeof(int), descend);
    while(len--)
        printf("%d", num[len]);

    return 0;
}