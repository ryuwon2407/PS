#include <stdio.h>

int main()
{
    int num;
    unsigned long long int sum = 0;

    scanf("%d", &num);
     for(int k = 1; k <= num; k++)
             sum += k * (num / k);

    printf("%ld\n", sum);
    return (0);
}

// g(1) = 1
// g(2) = 4
// g(3) = 8
// g(4) = 15

// 1 2 3 4 5 6 7 8 10
// 1 4 8 15 21 33 
// 1 3 4 7 6 12 8 15 

// 1000000 입력값을 생각을 못하고 자료형을 int 형으로 작성을 해서 틀림.
