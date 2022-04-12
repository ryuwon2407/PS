#include <stdio.h>

int main()
{
    int N              // 투표 수
    ,   temp           // 투표 결과 값
    ,   one_count  = 0 // 1 개수
    ,   zero_count = 0;// 0 개수

    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &temp);
        if(temp == 0)
            zero_count++;
        else
            one_count++;
    }
    printf("%s\n", (one_count > zero_count) ? "Junhee is cute!" : "Junhee is not cute!");

    return (0);
}