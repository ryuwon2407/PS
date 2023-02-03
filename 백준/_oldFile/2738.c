/**
 * @file 2738.c
 * @brief 2738. 행렬 덧셈
 * @date 2022-11-18
 * 
 * @text 2차원 배열을 
 * 
 */
#include <stdio.h>

int temp[100][100]   // A 저장
,   result[100][100];// B 저장

int main()
{
    int N  // 줄
    ,   M; // 행

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N * 2; i++){
        for(int j = 0; j < M; j++){
            if(i < N)
                scanf("%d", &temp[i][j]);
            else{
                scanf("%d", &result[i][j]);
                printf("%d ", result[i][j] + temp[i - N][j]);
            }
        }
        if(i > N)
            printf("\n");
    }
    return 0;
}