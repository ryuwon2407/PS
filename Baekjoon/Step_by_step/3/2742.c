#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    for ((int)num; num > 0; num--)
        printf("%d\n", num);
    return 0;
}