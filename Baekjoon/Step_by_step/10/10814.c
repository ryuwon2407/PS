#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 101
#define NUM_MAX 100001

int ft_cmpfunc(const void *a, const void *b);

typedef struct s_member {   // 회원 구조체
    int  age;
    char str[STR_MAX];
} t_member;

int main()
{
    int N; // 회원 수
    t_member *arr = (t_member *)malloc(sizeof(t_member) * NUM_MAX);// 회원 배열

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %s", &arr[i].age, arr[i].str);

    qsort((t_member *)arr, N, sizeof(t_member), ft_cmpfunc);    //quick 정렬

    for (int i = 0; i < N; i++)
    {
        printf("%d %s", arr[i].age, arr[i].str);
        if (i != N - 1)
            printf("\n");
    }

    return (0);
}

int ft_cmpfunc(const void *a, const void *b)
{
    t_member *temp_A = (t_member *)a;
    t_member *temp_B = (t_member *)b;

    if (temp_A->age > temp_B->age)
        return (1);
    else if (temp_A->age < temp_B->age)
        return (-1);
    else
        return (0);
}

// 추가적으로 배열 크기에서 틀렸다 ...
