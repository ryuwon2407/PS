#include <stdio.h>

int main()
{
    int X    // Fizz
    ,   Y    // Buzz
    ,   num; // 갯수

    scanf("%d %d %d", &X, &Y, &num);
    for(int i = 1; i <= num; i++)
    {
        if (i % X == 0 && i % Y == 0)
            printf("FizzBuzz\n");
        else if (i % X == 0)
            printf("Fizz\n");
        else if (i % Y == 0)
            printf("Buzz\n");
        else
            printf("%d\n", i);
    }

    return (0);
}