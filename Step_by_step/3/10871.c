#include <stdio.h>

int main()
{
    int A, X;
    int integer;
    
    scanf("%d %d", &A, &X);
    for (int i = 0; i < A; i++)
    {
        scanf("%d", &integer);
        if(integer < X)
            printf("%d ", integer);
    }

    return 0;
}