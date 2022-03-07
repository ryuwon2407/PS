#include <stdio.h>

int main()
{
    int testcase_num;
    int A, B;

    scanf("%d", &testcase_num);
    for (int i = 0; i < testcase_num; i++)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }

    return 0;
}