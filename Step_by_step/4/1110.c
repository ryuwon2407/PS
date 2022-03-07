#include <stdio.h>

int main()
{
    int N;
    int result = 0, count = 1;

    scanf("%d", &N);
    if(N < 10)
         N *= 10;
    result = (N % 10) * 10 + (N / 10 + N % 10) % 10;
    while(N != result)
    {
        result = (result % 10) * 10 + (result / 10 + result % 10) % 10; 
        count++;
    }
    printf("%d", count);
    return 0;
}