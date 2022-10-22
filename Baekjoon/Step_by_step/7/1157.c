#include <stdio.h>
#define ALPHABET_MAX 26
#define STR_MAX 1000000

int main()
{
    int alphabet[ALPHABET_MAX] = { 0, };
    int top = -1;
    char str[STR_MAX];

    scanf("%s", str);
    for(int i = 0; str[i]; i++)
    {
        if(str[i] >= 97)
            alphabet[(int)str[i] - 97]++;
        else
            alphabet[(int)str[i] - 65]++;
    }
    for(int i = 0; i < ALPHABET_MAX; i++)
        if(alphabet[top] < alphabet[i])
            top = i;
    for(int i = 0; i < ALPHABET_MAX; i++)
        if(alphabet[top] == alphabet[i] && top != i)
        {
            printf("?\n");
            return 0;
        }
    printf("%c", top + 65);
}