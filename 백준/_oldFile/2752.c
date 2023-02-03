/**
 * @file 2752.c
 * @brief 2752. 세수정렬
 * @date 2022-10-31
 * 
 * @text 그냥 단순 버블정렬로 해결.
 * 
 */
#include <stdio.h>

int main()
{
    int N[3]
    ,   temp;

    for(int i = 0; i < 3; i++)
        scanf("%d", &N[i]);

    for(int i = 0; i < 3; i++)
        for(int j = i; j < 3; j++)
            if(N[i] > N[j])
            {
                temp = N[i];
                N[i] = N[j];
                N[j] = temp;
            }
    printf("%d %d %d\n", N[0], N[1], N[2]);

    return 0;
}