#include <stdio.h>

int main()
{
    int unique_num[5];

    scanf("%d %d %d %d %d", 
    &unique_num[0], &unique_num[1], &unique_num[2], &unique_num[3], &unique_num[4]);

    printf("%d\n", 
    ((unique_num[0] * unique_num[0]) + (unique_num[1] * unique_num[1]) + (unique_num[2] * unique_num[2]) + (unique_num[3] * unique_num[3]) + (unique_num[4] * unique_num[4])) % 10);

    return (0);
}