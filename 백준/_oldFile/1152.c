#include <stdio.h>

#define STR_MAX 1000000

int main()
{
    char str[STR_MAX];
    int word_count = 0;
    int flag = 1;

    scanf("%[^\n]s", str);
    for (int i = 0; str[i]; i++)
    {
        if(str[i] == ' ')
            flag = 1;
        else if(flag && str[i] != ' ')
        {
            word_count++;
            flag = 0;
        }
    }
    printf("%d\n",word_count);
    
    return 0;
}