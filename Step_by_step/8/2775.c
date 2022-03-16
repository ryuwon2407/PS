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
    int test_case,  // 테스트 케이스 수
                k,  // 층 수 
                n;  // 호 수

    scanf("%d", &test_case);
    for(int i = 0; i < test_case; i++)
    {
        scanf("%d\n%d", &k, &n);
        printf("%d\n", f(k + n, k + 1));
    }
    return 0;
} 
// 15! / 2 * 13!
// 1 14

// 4 / 2 3