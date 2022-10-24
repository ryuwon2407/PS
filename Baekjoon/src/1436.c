#include <stdio.h>

int main()
{
    int N        // 입력값
    ,   i        // 
    ,   num = 0  // 종말의 수 갯수 (666은 기본적으로 1개 찾았다고 가정하고 시작)
    ,   temp = 0;// 검증

    scanf("%d", &N);
    for(i = 0; num != N; i++)
    {
        temp = i;
        while(temp != 0)
            if(temp % 1000 == 666)
            {
                num++;
                break;
            }
            else
                temp /= 10;
    }
    printf("%d\n", i - 1);

    return 0;
}