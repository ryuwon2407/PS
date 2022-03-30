#include <stdio.h>

#define MAX 100

int main()
{
    int N       // 카드의 개수
    ,   M       // 카드 최대 핪
    ,   num[MAX]// 숫자
    ,   sum = 0;// 합
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    for(int p1 = 0; p1 < N - 2; p1++)
        for(int p2 = p1 + 1; p2 < N - 1; p2++)
            for(int p3 = p2 + 1; p3 < N; p3++)
                if((sum < num[p1] + num[p2] + num[p3]) && (M >= num[p1] + num[p2] + num[p3]))
                    sum = num[p1] + num[p2] + num[p3];
    printf("%d\n", sum);

    return (0);
}


// 0 1 2
// 0 1 3
// 0 1 4
// 0 2 3
// 0 2 4
// 0 3 4
// 1 2 3
// 1 2 4
// 1 3 4
// 2 3 4