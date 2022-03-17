#include <stdio.h>
#include <time.h>

int main()
{
    double start, end;
    int num = 2147483647;    //입력 받은 숫자
    int i;

    start = (double)clock() / CLOCKS_PER_SEC;

    if(num == 0 || num == 1)
        printf("%d : Not Prime\n", num);
    for(i = 2; i < num / 2; i++)
        if(num % i == 0) break;
    if(num == i)
        printf("%d : Prime\n", num);
    else
        printf("%d : Prime\n", num);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("%lf\n", (end - start));
}

//