/**
 * @file 7568.c
 * @brief 7568. 덩치
 * @date 2022-11-23
 * 
 * @text 단순히 키와 몸무게를 비교하여 자신보다 더 큰 덩치 수 + 1 출력하면 클리어!
 * 
 */
#include <stdio.h>

#define HUMAN_MAX 50

typedef struct human{
    int weight
    ,   height;
}human;

human arr[HUMAN_MAX];

int main()
{
    int N
    ,   cnt;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &arr[i].weight, &arr[i].height);
    
    // 자신보다 더 큰 덩치 수 출력
    for(int i = 0; i < N; i++){
        cnt = 0;
        for(int j = 0; j < N; j++){
            if(arr[i].weight < arr[j].weight && arr[i].height < arr[j].height)
               cnt++;
        }
        printf("%d ", cnt + 1);
    }

    return 0;
}