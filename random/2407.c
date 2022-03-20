// 2775번 풀고 덤으로 푼 문제

#include <stdio.h>

int f(int n, int k)
{
    if (k == n) 
        return 1;
    else if (k == 1) 
        return n;
    else 
        return f(n - 1, k - 1) + f(n - 1, k);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    printf("%d", f(n,m));
}