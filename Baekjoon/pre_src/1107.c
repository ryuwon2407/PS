/**
 * @file 1107.c
 * @brief 1107. 리모컨
 * @date 2022-10-27
 * 
 * @text 처음에 브루트포스처럼 문제를 풀지 않았고 최종적으로 채널 length를 초과하는 최적의 채널 할당을 하는 알고리즘을 짜지 못해서 
 *       다시 작성할 예정.
 * 
 */

// 기본채널은 100.
// 자릿수 측정
// 첫째 자리부터 버튼이 있는지 확인
// => 버튼이 없을경우 1, -1, 2, -2 ... 형태로 확인 (배열 초과하지 않게 조심)
// 모든 자릿수 버튼 최적의 숫자 할당
// N과 최적의 수와의 대소 비교를 통해 +1 연산이 좋을지 -1 연산이 좋을지 판단
// +1, -1 카운팅
// (채널자릿 수) + (+1, -1 카운팅) => 프린트.

// 기본 채널이 있는줄 모르고 코드를 작성하다가 차후에 발견... => 해결
// 80000 같은 경우 70000으로 최대값이 입력됨.. => 해결
// 99999 같은 경우 100000으로 채널 할당을 못하는 문제.. => 코드 재작성. (알고리즘 오류)

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BUTTON_MAX 10

int button[BUTTON_MAX];


int continuous_button_select(int start_num, int end_num, int len, int i)
{
    int num;

    if(start_num < end_num){
        for(num = start_num; num <= end_num; num++)
        {
            if(button[num] == 0){
                if(num == 0 && i == len)
                    continue;
                else
                    break;
            }
        }
    }
    else{
        for(num = start_num; num >= end_num; num--){
            if(button[num] == 0){
                if(num == 0 && i == len)
                    continue;
                else
                    break;
            }
        }
    }

    return num;
}

int main()
{
    int N            // 이동 할 채널
    ,   M            // 고장난 버튼 수
    ,   len     = 0  // 채널 자릿수
    ,   ch_bak  = 0  // 채널 backup
    ,   temp = 0, temp_2 = 0, temp_3 = 0
    ,   ch_temp = 0, ch_temp_2 = 0, ch_temp_3 = 0;

    scanf("%d\n%d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &temp);
        button[temp]++;
    }

    if(N < 10)
        len = 1;
    else
        for(int i = N; i > 0; i /= 10)
            len++;

    ch_bak = N;
    for(int i = len; i > 0; i--)
    {
        if((temp < temp_3) && i != len && len != 1)
            temp = continuous_button_select(9, 0, len, i);
        else if((temp > temp_3) && i != len && len != 1)
            temp = continuous_button_select(0, 9, len, i);
        else
        {
            temp = temp_3 = N / (int)pow(10, i - 1);
            for(int j = 0; j < BUTTON_MAX * 2; j++)
            {
                temp_2 = temp + (int)pow(-1, j + 1) * (int)floor((j+1) / 2);
                if((temp_2 > -1 && temp_2 < 10) && button[temp_2] == 0){
                    if(temp_2 == 0 && i == len && len != 1)
                        continue;
                    else{
                        temp = temp_2;
                        break;
                    }
                }
            }
        }
        ch_temp += temp * (int)pow(10, i - 1);
        N %= (int)pow(10, i - 1);
    }

    if(M == 10)
        printf("%d\n", abs(ch_bak - 100));
    else if(len != 1){
        // 한자리 더 많을때 채널 최저값
        for(int i = len + 1; i > 0; i--){
            temp = continuous_button_select(0, 9, len + 1, i);
            ch_temp_2 += temp * (int)pow(10, i - 1);
        }
        
        // 한자리 더 적을때 채널 최대값
        for(int i = len - 1; i > 0; i--){
            temp = continuous_button_select(9, 0, len - 1, i);
            ch_temp_3 += temp * (int)pow(10, i - 1);
        }

        if(abs(ch_bak - ch_temp) + len < abs(ch_bak - ch_temp_2) + len - 1 &&  abs(ch_bak - ch_temp) + len < abs(ch_bak - ch_temp_3) + len - 1)
            temp = abs(ch_bak - ch_temp) + len;
        else if(abs(ch_bak - ch_temp_2) + len - 1 <  abs(ch_bak - ch_temp) + len && abs(ch_bak - ch_temp_2) + len - 1 < abs(ch_bak - ch_temp_3) + len - 1)
            temp = abs(ch_bak - ch_temp_2) + len + 1;
        else
            temp = abs(ch_bak - ch_temp_3) + len - 1;
        printf("%d\n", temp <= (abs(ch_bak - 100)) ? temp : (abs(ch_bak - 100)));
    }
    else
        printf("%d\n",  abs(ch_bak - ch_temp) + len <= (abs(ch_bak - 100)) ?  abs(ch_bak - ch_temp) + len : (abs(ch_bak - 100)));

    return 0;
}