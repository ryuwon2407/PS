#include <stdio.h>

int main()
{
    int star_num;
    
    scanf("%d", &star_num);
    for (int i = 1; i <= star_num; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}