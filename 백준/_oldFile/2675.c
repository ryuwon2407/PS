#include <stdio.h>

int main()
{
    int testcase_num, str_len;
    char str[20];

    scanf("%d", &testcase_num);
    for(int i = 0; i < testcase_num; i++)
    {
        scanf("%d %s", &str_len, str);
        
        for (int j = 0; str[j]; j++)
            for(int k = 0; k < str_len; k++)
                printf("%c",str[j]);
        
        printf("\n");
    }
    return 0;
}