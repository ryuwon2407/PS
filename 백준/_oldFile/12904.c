#include <stdio.h>
#include <string.h>

#define S_MAX 1000
#define T_MAX 1001

void reverse_str(char *str);

int main()
{
    char S[S_MAX]     // 문자열 S
    ,    T[T_MAX];    // 문자열 T
    int  S_len, T_len;// 문자열의 길이

    scanf("%s", S);
    scanf("%s", T);
    S_len = strlen(S);
    T_len = strlen(T);

    for (int i = T_len - 1; i > S_len - 1; i--)
    {
        if (T[i] == 'A')// 마지막 문자가 A인 경우(case 1)
            T[i] = 0;
        else            // 마지막 문자가 B인 경우(case 2)
        {
            T[i] = 0;
            reverse_str(T);
        }
    }

    if (strcmp(S, T) != 0)
        printf("0\n");
    else
        printf("1\n");
    
    return (0);
}

void reverse_str(char *str)
{
    char temp;
    int  str_len = strlen(str);
    
    for(int i = 0; i < str_len / 2; i++)
    {
        temp = str[i];
        str[i] = str[str_len - 1 - i];
        str[str_len - 1 - i] = temp;
    }

    return;
}