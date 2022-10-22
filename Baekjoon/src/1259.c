#include <stdio.h>
#include <string.h>

#define MAX 5   // 99999이하의 정수

int main()
{
    char str[MAX];
    int i       // 인덱스
    ,   str_len;// str 길이

    for (;;)
    {
        scanf("%s", str);
        if (str[0] == '0')
            break;
        
        str_len = strlen(str);
        for (i = 0; i < str_len / 2; i++)
            if (str[i] != str[str_len - i - 1])
                break;

        if(i == str_len / 2)
            printf("yes\n");
        else
            printf("no\n");
    }

    return (0);
}