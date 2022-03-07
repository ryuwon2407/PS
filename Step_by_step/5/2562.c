#include <stdio.h>

int main()
{
    int num[9] = { 0, };
    int max = 0, max_num = 0;

    for (int i = 0; i < 9; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i < 9; i++)
    {
        if (max < num[i])
        {
            max = num[i];
            max_num = i + 1;
        }
    }
    printf("%d\n%d", max, max_num);
    return 0;
}