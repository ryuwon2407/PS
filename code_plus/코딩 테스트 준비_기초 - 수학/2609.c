#include <stdio.h>

int main()
{
    int num_1, num_2;

    scanf("%d %d", &num_1, &num_2);
    for(int i = 1; i <= num_1 && i <= num_2; i++)
    {
        if(num_1 % i == 0 && num_2 % i == 0)
        {
            printf("%d", i);
            break;
        }
    }
    for(int i = 1; 1 ;i++)
    {
        
    }
}