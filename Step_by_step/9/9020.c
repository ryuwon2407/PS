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

//241

void Goldbach(int check, int *array)
{
    int i, j;
    int num_1, num_2;

    for(i = 2; i <= check / 2 ; i++)
    {
        if(array[i] == 0)
            for(j = 2; j <= check ;j++)
                if(array[j] == 0)
                    if(i + j == check)
                    {
                        num_1 = i;
                        num_2 = j;
                    }
    }
    printf("%d %d\n", num_1, num_2);
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