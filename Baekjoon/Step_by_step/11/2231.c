#include <stdio.h>

int main()
{
    int N           // 자연수 N
    ,   i
    ,   sum = 0;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        for(int temp = i; temp != 0; temp /= 10)
            sum += temp % 10;

        if(sum + i == N)
            break;
        else
            sum = 0;
    }

    if(i == N)
        printf("0\n");
    else
        printf("%d\n", i);

    return(0);
}