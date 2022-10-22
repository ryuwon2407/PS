#include <stdio.h>

int main()
{
    int star_num;
    
    scanf("%d", &star_num);
    for (int i = 1; i <= star_num; i++)
    {
        for (int blank = star_num; blank > i; blank--)
            printf(" ");
        for (int star = 1; star <= i; star++)
            printf("*");
        printf("\n");
    }
    return 0;
}