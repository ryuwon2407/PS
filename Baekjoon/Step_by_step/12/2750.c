#include <stdio.h>

#define MAX 1000

int main()
{
    int N        // 줄의 갯수
    ,   temp     // 임시 temp
    ,   num[MAX];// num

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    for(int i = 0; i < N - 1; i++)  // 버블 sort
    {
        for(int j = 0; j < N - 1; j++)
        {
            if(num[j] > num[j + 1])
            {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        printf("%d", num[i]);
        if(i != N - 1)
            printf("\n");
    }

    return (0);
}