/**
 * @file 10991.c
 * @brief 10991. 별 찍기 - 16
 * @date 2022-11-30
 * 
 * @text 
 * 
 */

#include <stdio.h>

int main(){
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i - 1; j++) // * 앞 공백 출력
            printf(" ");
        for(int k = 0; k < i + 1; k++) // * 출력
            printf("* ");
        printf("\n");
    }

    return 0;
}