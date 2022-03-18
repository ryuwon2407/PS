#include <stdio.h>

int prime_check(int num);

int main()
{
    int n;
    int prime_count = 0;

    while(1)
    {
        scanf("%d\n", &n);
        if(n == 0)
            break;
        for(int i = n; i <= 2 * n; i++)
        {
            prime_count = prime_check(i);
        }
    }
    printf("%d\n", prime_count);

    return (0);
}



int prime_check(int num)
{
    int prime_check;

    if (1 < num)
    {
        for(prime_check = 2; prime_check * prime_check <= num && prime_check < 46341; prime_check++)
        {
            if (num % prime_check == 0)
                break;
        }
        if(!(prime_check * prime_check <= num))
            return(1);
    }

    return (0);
}