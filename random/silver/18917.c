#include <stdio.h>

int main()
{
    int           M           // 쿼리 개수
    ,             case_num    // case 번호
    ,             datum;      // 데이터 값
    int long long sum = 0     // 3번을 위한 sum 값
    ,             xor_num = 0;// 4번을 위한 xor 데이터 

    scanf("%d", &M);
    while(M--)
    {
        scanf("%d", &case_num);
        if(case_num == 1)      // case 1
        {
            scanf("%d", &datum);
            sum += datum;
            xor_num ^= datum;  // case 2
        }
        else if(case_num == 2)
        {
            scanf("%d", &datum);
            sum -= datum;
            xor_num ^= datum;
        }
        else if(case_num == 3) // case 3
            printf("%ld\n", sum);
        else if(case_num == 4) // case 4
            printf("%ld\n", xor_num);
    }
    return (0);
}