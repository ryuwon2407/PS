#include <stdio.h>

int main()
{
    int num, temp;
    int prime_count = 0;
    int prime_check;

    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        if (1 < temp)
        {
            for(prime_check = 2; prime_check * prime_check <= temp && prime_check < 46341; prime_check++)
            {
                if (temp % prime_check == 0)
                    break;
            }
            if(!(prime_check * prime_check <= temp))
                prime_count++;
        }
    }
    printf("%d\n", prime_count);
    
    return 0;
}