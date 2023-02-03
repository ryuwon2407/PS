#include <stdio.h>

int main()
{
    int max = 0, min = 1000000;
    int result = 0;
    int div_num;

    scanf("%d", &div_num);
    int div[div_num];
    for(int i = 0; i < div_num; i++)
    {
        scanf("%d", &div[i]);
        if(max <= div[i])
            max = div[i];
        if(min >= div[i])
            min = div[i];
    }
    printf("%d\n", max * min);

    return 0;
}