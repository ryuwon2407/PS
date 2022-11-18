#include <stdio.h>

int main()
{
    int M, N;
    int min, sum = 0;
    int prime_check, flag = 1;

    scanf("%d\n%d", &M, &N);
    for(int i = M; i <= N; i++)
    {
        if (1 < i)
        {
            for(prime_check = 2; prime_check * prime_check <= i && prime_check < 46341; prime_check++)
            {
                if (i % prime_check == 0)
                    break;
            }
            if(!(prime_check * prime_check <= i) && !flag)
                sum += i;
            else if(!(prime_check * prime_check <= i) && flag)
            {
                min = i;
                sum += i;
                flag = 0;
            }
        }
    }
    if (sum == 0)
        printf("-1\n");
    else
        printf("%d\n%d\n", sum, min);
}

//60 100