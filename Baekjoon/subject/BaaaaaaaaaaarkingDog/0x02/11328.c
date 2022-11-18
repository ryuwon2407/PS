/**
 * @file 11328.c
 * @brief 11328. Strfry
 * @date 2022-11-02
 * 
 * @text 입력된 문자열을 무작위로 재배열하여 새로운 문자열을 만드는 함수인 Strfry를 구현하는 문제.
 *       해당 문제를 포인터를 줬다가 런타임 에러, 배열로 바꾸면서 문자열 길이를 또 100으로 착각해서 한번 더 틀렸다.
 * 
 */
#include <stdio.h>
#include <string.h>

#define ALHPA_NUM 26

int alhpa_a[ALHPA_NUM]
,   alhpa_b[ALHPA_NUM];

int main()
{
    int i
    ,   N
    ,   len_a
    ,   len_b;
    char temp[1001];

    scanf("%d", &N);
    while(N--)
    {
        for(i = 0; i < ALHPA_NUM; i++){
            alhpa_a[i] = 0; alhpa_b[i] = 0;
        }

        scanf("%s", temp);
        len_a = strlen(temp);
        for(i = 0; i < len_a; i++)
            alhpa_a[temp[i] - 97]++;
        
        scanf("%s", temp);
        len_b = strlen(temp);
        for(i = 0; i < len_b; i++)
            alhpa_b[temp[i] - 97]++;
        
        if(len_a != len_b)
            printf("Impossible\n");
        else
        {
            for(i = 0; i < ALHPA_NUM; i++){
                if(alhpa_a[i] != alhpa_b[i])
                    break;
            }
            if(i == ALHPA_NUM)
                printf("Possible\n");
            else
                printf("Impossible\n");
        }
    }
    return 0;
}