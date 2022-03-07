#include <stdio.h>

int main()
{
    int one, two, three;
    int money;

    scanf("%d %d %d", &one, &two, &three);
    if (one == two && two == three)
        money = 10000 + one * 1000;
    else if (one == two)
        money = 1000 + one * 100;
    else if (two == three)
        money = 1000 + two * 100;
    else if (three == one)
        money = 1000 + three * 100;
    else
    {
        if(one > two && one > three)
            money = one * 100;
        else if(one < two && two > three)
            money = two * 100;
        else if(one < three && two < three)
            money = three * 100;
    }
    printf("%d\n", money);
    return 0;
}