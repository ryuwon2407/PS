#include <stdio.h>

int main()
{
    int num, result = 0;
    int temp;

    scanf("%d", &num);
    
    for(int i = 0; i < num; i++)
    {
        scanf("%1d", &temp);
        result += temp;
    }
    printf("%d\n", result);
    return 0;
}