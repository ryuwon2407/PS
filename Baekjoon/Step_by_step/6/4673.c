#include <stdio.h>

int self_check(int num)
{
    int sum = num;
    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return (sum);
}

int main()
{
    int check, sum;

    for (int i = 1; i <= 10000; i++)
    {
        for(check = 1; check <= i; check++)
        {
            sum = self_check(check);
            if(i == sum)
                break;
        }
        if(i == check - 1)
            printf("%d\n", i);
    }
    return 0;
}