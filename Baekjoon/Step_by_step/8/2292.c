#include <stdio.h>

int six_power(int i)
{
    int result = 0;
    while(i--)
        result += 6;
    return result;
}

int main()
{
    int i = 1, sum = 1;
    int N;

    scanf("%d", &N);
    if(N == 1)
        printf("1\n");
    else
    {
        while(!(sum - 1 <= N && N <= sum + six_power(i)))
        {
            sum += six_power(i);
            i++;
        }
        printf("%d\n", i + 1);
    }
    return 0;
}