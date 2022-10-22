#include <stdio.h>

int main()
{
    int num_1, num_2;
    int rev_num1 = 0, rev_num2 = 0;

    scanf("%d %d", &num_1, &num_2);
    rev_num1 = (num_1 % 10) * 100 + (num_1 % 100 / 10) * 10 + num_1 / 100;
    rev_num2 = (num_2 % 10) * 100 + (num_2 % 100 / 10) * 10 + num_2 / 100;

    if(rev_num1 > rev_num2)
        printf("%d\n", rev_num1);
    else
        printf("%d\n", rev_num2);
    return 0;
}