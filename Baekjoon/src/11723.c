#include <stdio.h>
#include <string.h>

#define S_MAX 21
#define STR_MAX 7

int S[S_MAX];

int main()
{
    int temp
    ,   command_num;

    char command_str[STR_MAX];
    
    scanf("%d", &command_num);
    while(command_num--)
    {
        scanf("%s", command_str);
        if(!strcmp(command_str, "add"))
        {
            scanf("%d", &temp);
            S[temp] = 1;
        }
        else if(!strcmp(command_str, "remove"))
        {
            scanf("%d", &temp);
            S[temp] = 0;
        }
        else if(!strcmp(command_str, "check"))
        {
            scanf("%d", &temp);
            if(S[temp] != 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if(!strcmp(command_str, "toggle"))
        {
            scanf("%d", &temp);
            S[temp] = S[temp] != 0 ? 0 : 1;
        }
        else if(!strcmp(command_str, "all"))
        {
            for(int i = 0; i < S_MAX; i++)
                S[i] = 1;
        }
        else 
        {
            for(int i = 0; i < S_MAX; i++)
                S[i] = 0;
        }
    }

    return (0);
}