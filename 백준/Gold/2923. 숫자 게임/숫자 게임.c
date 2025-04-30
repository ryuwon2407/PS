#include <stdio.h>
#include <string.h>

#define MAX 101

int num_1[MAX]
,   num_2[MAX];

int main()
{
    int N                        // 라운드 수
    ,   result                   // 출력 값(모든 쌍의 합의 최댓값의 최솟값)
    ,   min, max                 // 최대, 최소 인덱스
    ,   input_1, input_2         // input값 
    ,   temp_1[MAX], temp_2[MAX];// result 연산을 위한 임시 배열 temp 

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &input_1, &input_2);
        num_1[input_1]++;
        num_2[input_2]++;

        result = 0;
        max = 0, min = 100;
        memcpy(temp_1, num_1, sizeof(num_1));
        memcpy(temp_2, num_2, sizeof(num_2));
        while (min >= 1 && max <= 100)
        {
            while (min >= 1 && temp_1[min] == 0)
                min--;
            while (max <= 100 && temp_2[max] == 0)
                max++;
            
            if(min == 0 || max == 101)
                break;
            
            (result > min + max) ? result : (result = min + max);

            // 사용한 배열 제거(공통 포함)
            if (temp_1[min] > temp_2[max])
            {
                temp_1[min] -= temp_2[max];
                temp_2[max] = 0;
            }
            else
            {
                temp_2[max] -= temp_1[min];
                temp_1[min] = 0;
            }
        }
        printf("%d\n", result);
    }

    return (0);
}