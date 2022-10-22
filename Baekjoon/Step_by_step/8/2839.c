#include <stdio.h>

int main()
{
    int i,  // 5kg 체크 
        j;  // 3kg 체크
    int N;  // kg 

    scanf("%d", &N);
    for(i = N / 5; (N - i * 5) % 3 != 0 && i != 0; i--);
    N -= i * 5;

    if (N % 3 == 0)
        printf("%d\n", i + N / 3);
    else
        printf("-1\n");
    return 0;
}