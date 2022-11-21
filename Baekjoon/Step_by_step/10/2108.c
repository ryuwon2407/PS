/**
 * @file 2108.c
 * @brief 2108. 통계학
 * @date 2022-11-19
 * 
 * @text 첫째 줄 산술평균 => sum
 *       둘째 줄 중앙값   => 정렬 후 (수의 갯수 / 2)번째 값
 *       셋째 줄 최빈값(여러개 일시 두번째로 작은 값) => 
 *       넷째 줄 범위     => max - min
 * 
 */
#include <stdlib.h>
#include <stdio.h>

#define ROUND(A) (A > 0)?(int)(A + 0.5):(int)(A - 0.5)
#define RANGE_MAX 8001

int num[RANGE_MAX];

int compare(const void* A, const void* B){
    return *(int*)A > *(int*)B ? 1 : *(int*)A < *(int*)B ? -1 : 0;
}

int main()
{
    int    N
    ,      *arr;
    int    temp = 0
    ,      flag = 0
    ,      mode = 0
    ,      min  = 4000
    ,      max  = -4000;
    double sum  = 0;
    

    scanf("%d", &N);
    arr = (int *)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);

        num[arr[i] + 4000]++; // 최빈값 탐색용
        sum += arr[i];        // 산술평균 
        if(min > arr[i])      // 범위
            min = arr[i];
        if(max < arr[i])
            max = arr[i];
    }
    qsort(arr, N, sizeof(int), compare);

    for(int i = 0; i < RANGE_MAX; i++)  // 최빈값 탐색
        if(temp < num[i])
            temp = num[i];
    for(int i = 0; i < RANGE_MAX; i++){ // 같은 최빈값 여부 탐색
        if(temp == num[i] && flag == 1){
            mode = i - 4000;
            break;
        }
        else if(temp == num[i]){
            mode = i - 4000;
            flag++;
        }
    }

    printf("%.0f\n%d\n%d\n%d", sum / N, arr[N/2], mode, max - min);

    free(arr);
    return 0;
}