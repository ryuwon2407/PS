/**
 * @file 2566.c
 * @brief 2566. 최댓값
 * @date 2022-11-18
 * 
 * @text row, col 초기화를 깜빡해서 최대값이 0 일때 쓰레기 값이 들어가 한번 틀림..
 * 
 */
#include <stdio.h>

int main()
{
    int temp
    ,   row = 0
    ,   col = 0
    ,   max = 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &temp);
            if(max < temp){
                max = temp;
                col = i;
                row = j;
            }
        }
    }
    printf("%d\n%d %d", max, col + 1, row + 1);
    
    return 0;
}