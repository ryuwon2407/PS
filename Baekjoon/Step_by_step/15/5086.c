/**
 * @file 5086.c
 * @brief 5086. 배수와 약수
 * @date 2022-11-26
 * 
 * @text 약수 B % A, 배수 A % B 로 간단하게 품.
 * 
 */
#include <stdio.h>

int main()
{
    int A
    ,   B;

    while(1){
        scanf("%d %d", &A, &B);
        if(A == 0 && B == 0)     // 0 0일때 탈출
            break;

        if(B % A == 0)
            printf("factor\n");
        else if(A % B == 0)
            printf("multiple\n");
        else
            printf("neither\n");
    }

    return 0;
}