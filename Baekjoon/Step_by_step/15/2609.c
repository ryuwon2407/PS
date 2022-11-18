#include <stdio.h>

int main()
{
    int num_1, num_2;
    int temp = 1;

    scanf("%d %d", &num_1, &num_2);
    for(int i = 2; i <= num_2 && i<= num_1; i++)
        if(num_1 % i == 0 && num_2 % i == 0)
            temp = i;

    printf("%d\n%d\n", temp, num_1 * num_2 / temp);

    return (0);
}