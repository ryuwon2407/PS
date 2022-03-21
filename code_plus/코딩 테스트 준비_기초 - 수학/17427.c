#include <stdio.h>

int main()
{
    int divs_num;
    int divs_sum = 0;

    scanf("%d", &divs_num);
    for(int i = 1; i <= divs_num; i++)
    {
        for(int j = 1; j <=  i; j++)
        {
            if(i % j == 0)
                divs_sum += j;
        }
    }
    printf("%d", divs_sum);

    return (0);
}