#include <stdio.h>

#define MAX 1000001

void Goldbach(int check, int *array);
int *set_prime();

int main()
{
    int num;

    int *array;
    array = set_prime();

    while(1)
    {
        scanf("%d", &num);
        if(num == 0)
            break;
        Goldbach(num, array);
    }

    return (0);
}

void Goldbach(int check, int *array)
{
    for(int i = 2; i <= check; i++)
    {
        if(array[i] == 0 && array[check - i] == 0)
        {
            printf("%d = %d + %d\n", check, i, check - i);
            break;
        }
    }
    return;
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