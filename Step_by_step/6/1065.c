#include <stdio.h>

int seq_check(int i)
{
    int dig[3] = { 0, };

    if(i < 10)
        return 1;
    else if(i >= 10 && i < 100)
        return 1;
    else if(i >= 100 && i < 1000)
    {
        dig[0] = i / 100;
        dig[1] = (i % 100) / 10;
        dig[2] = i % 10;
        if(dig[0] - dig[1] == dig[1] - dig[2])
            return 1;
        else
            return 0;
    }
    else if(i == 1000)
        return 0;
}

int main()
{
    int num, count = 0;

    scanf("%d", &num);
    for(int i = 1; i <= num; i++)
    {
        if(seq_check(i))
            count++;
    }
    printf("%d\n", count);
    return 0;
}