/**
 * @file 4101.c
 * @brief 4101. 크냐?
 * @date 2022-11-01
 * 
 * @text 단순 비교
 * 
 */
#include <stdio.h>

int main()
{
    int N, M;
    
    while(1)
    {
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0)
            break;
        N > M ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}