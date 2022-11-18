#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int ft_compare(const void *a, const void *b);

int arr[MAX]; // 배열

int main()
{
    int N; // 수의 갯수

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    qsort(arr, N, sizeof(int), ft_compare);
    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);

    return (0);
}

int ft_compare(const void *a, const void *b)
{
    int num_1 = *(int *)a;
    int num_2 = *(int *)b;

    if (num_1 > num_2)
        return (1);
    else if(num_1 < num_2)
        return (-1);
    else
        return (0);
}