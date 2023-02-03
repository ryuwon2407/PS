#include <stdio.h>

#define MAX 10

int main()
{
    int N         // 동전 종류 개수
    ,   K         // 금액
    ,   count = 0 // 동전 개수
    ,   coin[MAX];// 동전 종류

    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &coin[i]);
    
    for (int i = N - 1; i >= 0 && K != 0; i--)
        if(K / coin[i] != 0)
        {
            count += K / coin[i];
            K %= coin[i];
        }
    printf("%d\n", count);

    return (0);
}