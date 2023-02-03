#include <stdio.h>

int recursive_factorial(int num);

int main()
{
    int N  // 자연수 N
    ,   K; // 정수 K

    scanf("%d %d", &N, &K);
    printf("%d\n", recursive_factorial(N) / (recursive_factorial(N - K) * recursive_factorial(K)));

    return (0);
}

int recursive_factorial(int num)
{
    if(num == 0 || num == 1)
        return (1);
    else
        return (num * recursive_factorial(num - 1));
}