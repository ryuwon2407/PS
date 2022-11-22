/**
 * @file 24060.c
 * @brief 24060. 알고리즘 수업 - 병합 정렬 1
 * @date 2022-11-22
 * 
 * @text 인자 값을 제대로 안줘서 한참 헤맸다..
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int K
,   result
,   cnt = 0;

void merge(int *A, int p, int q, int r){
    int tmp[r + 1];
    int i = p, j = q + 1, t = 1;
    while(i <= q && j <= r){
        if(A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }
    while(i <= q)
        tmp[t++] = A[i++];
    while(j <= r)
        tmp[t++] = A[j++];
    i = p, t = 1;
    while(i <= r){
        A[i++] = tmp[t++];
        if(++cnt == K) 
            result = tmp[t-1];
    }
}

void merge_sort(int *A, int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        merge_sort(A, p, q);     // 전반부
        merge_sort(A, q + 1, r); // 후반부
        merge(A, p, q, r);       // 병합
    }
}

int main()
{
    int N
    ,   *A;

    scanf("%d %d", &N, &K);
    A = (int *)malloc(sizeof(int) * N + 1);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    merge_sort(A, 0, N - 1);
    
    if(cnt < K)
        printf("-1\n");
    else
        printf("%d\n", result);

    return 0;
}