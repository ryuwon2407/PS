#include <stdio.h>

#define MAX 10

int num[MAX]; // 숫자 배열

int main()
{
    int  set_count = 0;// 세트 갯수
    char c;            // 입력 값
    
    while(scanf("%1[^\n]c", &c))
        num[c - 48]++;

    for(int i = 0; i < 10; i++)
    {
        if(set_count < num[i] && (i == 6 || i == 9))
            if((num[6] + num[9]) % 2 == 1)
                set_count = (num[6] + num[9]) / 2 + 1;
            else
                set_count = (num[6] + num[9]) / 2;
        else if(set_count < num[i])
            set_count = num[i];
    }
    printf("%d\n", set_count);

    return (0);
}