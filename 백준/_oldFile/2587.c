/**
 * @file 2587.c
 * @brief 2587. 대표값2
 * @date 2022-10-31
 * 
 * @text 버블정렬로 정렬 후 중앙 값 출력. => 바보같이 중앙값을 N[3] 이라고 넣고 계속 돌려서 중앙값이 제대로 안나와서 여러번 틀림.
 * 
 */
#include <stdio.h>

int main()
{
    int N[5]
    ,   temp
    ,   sum = 0;

    for(int i = 0; i < 5; i++){
        scanf("%d", &N[i]);
        sum += N[i];
    }

    for(int i = 0; i < 5; i++)
        for(int j = i; j < 5; j++)
            if(N[i] > N[j])
            {
                temp = N[i];
                N[i] = N[j];
                N[j] = temp;
            }
    printf("%d\n%d\n", sum / 5, N[2]);

    return 0;
}