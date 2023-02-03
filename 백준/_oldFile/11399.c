#include <stdio.h>

#define MAX 1000

int withdraw_time[MAX];

int main()
{
    int N        // 사람의 수
    ,   sum = 0  // 필요한 시간의 합의 최솟값
    ,   temp = 0;// 임시 저장
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &withdraw_time[i]);

    for(int i = 0; i < N - 1; i++)
        for(int j = 0; j < N - 1; j++)
            if(withdraw_time[j] > withdraw_time[j + 1])
            {
                temp = withdraw_time[j];
                withdraw_time[j] = withdraw_time[j + 1];
                withdraw_time[j + 1] = temp;   
            }

    temp = 0;
    for(int i = 0; i < N; i++)
        sum += temp += withdraw_time[i];

    printf("%d\n", sum);

    return (0);
}

// 퀵 정렬 쓰려다가 타임 초과 안날꺼같아서 버블 사용