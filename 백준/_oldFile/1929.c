#include <stdio.h>

#define MAX 1000000

int main()
{
   int M, N;
   int temp[MAX];
   temp[1] = 1;

   scanf("%d %d", &M, &N);
   
    for(int i = 2; i <= N; i++)
        for(int j = 2; i * j <= N; j++)
            temp[i*j] = 1;

    for(int i = M; i <= N; i++)
        if(temp[i] == 0)
            printf("%d\n", i);

    return (0);
}