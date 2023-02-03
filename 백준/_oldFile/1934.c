#include <stdio.h>

int cal_gcd(int num_1, int num_2);

int main()
{
    int num_1
    ,   num_2
    ,   testcase_num;

    scanf("%d", &testcase_num);
    while (testcase_num--)
    {
        scanf("%d %d", &num_1, &num_2);
        printf("%d\n", (num_1 * num_2 ) / cal_gcd(num_1, num_2));
    }

    return (0);
}

int cal_gcd(int num_1, int num_2)
{
    int temp;

    while (num_2 > 0)
    {
        temp = num_1;
        num_1 = num_2;
        num_2 = temp % num_2;
    }

    return (num_1);
}

// 유클리드 호제법
// (a * b) / 최대공약수