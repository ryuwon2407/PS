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
#include <string.h>
#include <stdio.h>

#define MAX 4001

int num[MAX];

int main()
{
    int N
    ,   temp
    ,   mode
    ,   sum = 0
    ,   count = 0
    ,   max = 0
    ,   min = 500001;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &temp);

        num[temp]++;
        sum += temp;
        if(min > temp)
            min = temp;
        if(max < temp)
            max = temp;
    }

    temp = 0;
    for(int i = 0; i < MAX; i++)
        if(temp < num[temp])
            temp = num[temp];

    for(int i = 0; i < MAX; i++){
        if(temp == num[i] && count == 1){
            mode = i;
            break;
        }
        else if(temp == num[i]){
            mode = i;
            count++;
        }
    }
    
    printf("%d\n%d\n%d\n", (int)(sum / N), mode, max - min);
}