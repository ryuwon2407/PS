#include <stdio.h>

int main()
{
    int A, B, C;
    int max;

    while(1)
    {
        scanf("%d %d %d", &A, &B, &C);
        max = A > B ? (A > C ? A : C) : (B > C ? B : C);
        if(A == 0 && B == 0 && C == 0)
            break;
        else if( max == A && (max * max) == (B * B) + (C * C))
            printf("right\n");
        else if( max == B && (max * max) == (A * A) + (C * C))
            printf("right\n");
        else if( max == C && (max * max) == (A * A) + (B * B))
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}