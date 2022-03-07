#include <stdio.h>

int main()
{
    int num1, num2;
    scanf("%d\n%d", &num1, &num2);
    printf("%d\n", num1 * (num2 % 10));
    printf("%d\n", num1 * (num2 / 10 % 10));
    printf("%d\n", num1 * (num2 / 100));
    printf("%d\n", num1 * num2);
}