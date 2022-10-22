#include <stdio.h>

int main()
{
    int integar;

    scanf("%d", &integar);
    int num[integar];

    for (int i = 0; i < integar; i++)
        scanf("%d", &num[i]);

    int max = num[0], min = num[0];
    for (int i = 0; i < integar; i++)
    {
        if(max < num[i])
            max = num[i];
        if(min > num[i])
            min = num[i];
    }
    printf("%d %d\n", min, max);
    
    return 0;
}