#include <stdio.h>

#define MAX 10001

void Goldbach(int check, int *array);
int *set_prime();

int main()
{
    int testcase_num, check;

    int *array;
    array = set_prime();

    scanf("%d", &testcase_num);
    for(int i = 0; i < testcase_num; i++)
    {
        scanf("%d", &check);
        Goldbach(check, array);
    }

    return (0);
}

void Goldbach(int check, int *array)
{
    int i = check / 2
    ,   j = 0;

    while(1)
    {
        if(!array[i + j] && !array[i - j])
        {
            printf("%d %d\n", i - j, i + j);
            break;
        }
        j++;
    }
}


int *set_prime()
{
    static int array[MAX];
    
    array[1] = 1;
    for(int i = 0; i <= MAX; i++) array[i] = 0; // 초기화

    for(int i = 2; i <= MAX; i++)
        for(int j = 2; i * j <= MAX; j++)
            array[i*j] = 1;
    
    return (array);
}