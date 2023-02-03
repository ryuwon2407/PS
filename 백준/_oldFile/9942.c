#include <stdio.h>
#include <math.h>

unsigned long long recu(int n, int r)
{
    unsigned long long k = n - round(sqrt(2 * n + 1)) + 1;
    unsigned long long result;

    if(n == 1)
        return 1;
    if(r == 3)
        return (pow(2, n) - 1);

    return result = recu(k, r) * 2 + recu(n - k, r -1);
}

int main()
{
    int N
    ,   i = 1;

    while(scanf("%d", &N) != EOF)
        printf("Case %d: %lld\n", i++, recu(N, 4));

    return 0;
}