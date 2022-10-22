#include <stdio.h>

#define STR_MAX 101
#define ALPHABET_MAX 26

int alpha[ALPHABET_MAX]; // 초기화를 위해 전역변수 선언

int main()
{
    char temp[STR_MAX];
    int  i = -1;

    scanf("%s", temp);
    while(temp[++i])
        alpha[(int)temp[i] - 97]++;

    for(int i = 0; i < ALPHABET_MAX; i++)
    {
        if(i != ALPHABET_MAX - 1)
            printf("%d ", alpha[i]);
        else
            printf("%d\n", alpha[i]);
    }

    return (0);
}