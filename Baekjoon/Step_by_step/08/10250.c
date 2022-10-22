#include <stdio.h>

int main()
{
    int num;
    int H,  // 층 수
        W,  // 호 수
        N;  // N 번째 방문자
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d %d %d", &H, &W, &N);
        if(N % H == 0)
            printf("%d\n", H * 100 + N / H);
        else
            printf("%d\n",(N % H) * 100 + N / H + 1);
    }
}
// 16 17 18 19 20
// 11 12 13 14 15
// 6  7  8  9  10
// 1  2  3  4  5

// 4 5 19
