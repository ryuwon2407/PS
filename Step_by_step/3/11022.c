#include <stdio.h>

int main()
{
    int testcase_num;
    int A, B;
    
    scanf("%d", &testcase_num);
    for (int i = 1; i <= testcase_num; i++)
    {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d + %d = %d\n", i, A, B, A + B);
    }
    return 0;
}