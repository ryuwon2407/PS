#include <stdio.h>
#include <stdlib.h>

#define MAX 50 + 1

int main()
{
    int flag = 0
    ,   num_count = 0
    ,   num[MAX];
    char str[MAX]
    ,    sign[MAX]
    ,    sign_count = 0
    ,    temp[5];

    scanf("%s", str);
    for(int i = 0; i < MAX; i++)
    {
        if(str[i] == '+' || str[i] == '-')
        {
            sign[sign_count++] = str[i];
            for(int j = 0; j <= (i - 1) - flag; j++)
                temp[j] = str[flag + j];
            num[num_count++] = atoi(temp);
        }
    }

    for(int i; i < num_count; i++)
    {
        if()
    }


}