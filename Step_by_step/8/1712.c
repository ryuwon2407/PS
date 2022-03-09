#include <stdio.h>

int main()
{
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);
    if( C - B <= 0)
        printf("-1\n");
    else
        printf("%d\n", A / (C - B) + 1);
    return 0;
}