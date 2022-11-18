/**
 * @file 2563.c
 * @brief 2563. 색종이
 * @date 2022-11-18
 * 
 * @text for문 조건 때문에 한번 틀림
 * 
 */
#include <stdio.h>

#define X 100
#define Y 100

int arr[X][Y];

int main()
{
    int N
    ,   temp_x
    ,   temp_y
    ,   result = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &temp_x, &temp_y);
        for(int j = temp_x; j < temp_x + 10; j++)
            for(int k = temp_y; k < temp_y + 10; k++)
                arr[j][k] = 1;
    }

    for(int i = 0; i < X; i++)
        for(int j = 0; j < Y; j++)
            if(arr[i][j] == 1)
                result++;
    
    printf("%d", result);
    return 0;
}