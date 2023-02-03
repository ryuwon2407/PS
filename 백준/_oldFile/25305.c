/**
 * @file 25305.c
 * @brief 25305. 커트라인
 * @date 2022-11-18
 * 
 * @text qsort로 처리
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int arr[1000];

int compare(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

int main()
{
    int N
    ,   k;

    scanf("%d %d", &N, &k);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    qsort(arr, N, sizeof(arr[0]), compare);
    printf("%d\n", arr[k-1]);

    return 0;
}