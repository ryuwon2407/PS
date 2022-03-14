#include <stdio.h>

int main()
{
    int N;      //소인수 분해 할 정수
    int check;  //나눠지는 수 확인

    scanf("%d", &N);
    while (N != 0)
    {
        if(N == 1) break;
        for(check = 2; N % check != 0; check++);
        
        printf("%d\n", check);
        
        if(N == check)
            break;
        else
            N /= check;
    }
}