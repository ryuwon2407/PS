#include <stdio.h>

#define MAX 1000001

char P[MAX]
,    S[MAX];

int main()
{
    int N 
    ,   M
    ,   i, j
    ,   count = 0;

    // Pn 제작.
    scanf("%d", &N);
    P[0] = 'I', P[1] = 'O', P[2] = 'I';
    for (int i = 3; i < 3 + (N - 1) * 2; i += 2)
        P[i] = 'O', P[i + 1] = 'I';
    
    scanf("%d", &M);
    scanf("%s", S);
    
    for (i = 0; i < M; i++)
    {
        for (j = 0; (j + i < i + 3 + (N - 1) * 2) && i + 3 + (N - 1) * 2 <= M; j++)
            if (S[j + i] != P[j])
                break;
        if (i + j == i + 3 + (N - 1) * 2)
            count++;
    }
    printf("%d", count);

    return (0);
}

// 백만 + 1 을 했어야했는데 백만만 함...
// 시간 초과
