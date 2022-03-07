#include <stdio.h>

int main()
{
    int num[10], result[10] = { 0, };
    int count = 0;
    int check;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
        result[i] = num[i] % 42;
    }
    for (int i = 0; i < 10; i++)
    {
        for (check = 0; check < i; check++)
            if(result[i] == result[check])
                break;
        if(i == check)
            count++;
    }
    printf("%d\n", count);
    return 0;
}