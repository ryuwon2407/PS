#include <stdio.h>

int recursive_factorial(int N);

int main()
{
    int N;
    scanf("%d", &N);
    
    printf("%d\n", recursive_factorial(N));
}

int recursive_factorial(int N)
{
    int sum = 0;

    if(N == 0 || N == 1)
        return (1);
    else
        sum = N * recursive_factorial(N - 1);

    return (sum);
}