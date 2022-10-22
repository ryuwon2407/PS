#include <stdio.h>

#define TYPE 6

int main()
{
    int N
    ,   chess[TYPE] = {1, 1, 2, 2, 2, 8};

    for (int i = 0; i < TYPE; i++)
    {
        scanf("%d", &N);
        if(i == TYPE - 1)
            printf("%d\n", chess[i] - N);
        else
            printf("%d ", chess[i] - N);
    }
    
    return 0;
}


// 킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개