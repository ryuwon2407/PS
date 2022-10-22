#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testcase_num;
    int A, B;
    int *result;

    scanf("%d", &testcase_num);
    result = (int *)malloc(sizeof(int) * testcase_num);
    for (int i = 0; i < testcase_num; i++)
    {
        scanf("%d %d", &A, &B);
        result[i] = A + B;
    }
    for (int i = 0; i < testcase_num; i++)
        printf("%d\n", result[i]);
    
    free(result);
    return 0;
}