#include <stdio.h>

int main()
{
    int only_one;
    int num, len;

    while(scanf("%d", &num) != EOF)
    {
        only_one = 1;
        len = 1;
        while(1)
        {
            if(only_one % num == 0)
                break;
            only_one = (only_one * 10 + 1) % num;
            len++;
        }
        printf("%d\n",len);
    }
    return 0;
}