#include <stdio.h>

int main()
{
    char str[100];
    int alphabet[26] = { -1, };
    for(int i = 0; i < 26; i++)
        alphabet[i] = -1;

    scanf("%s", str);
    for(int i = 0; str[i]; i++)
        if (alphabet[(int)str[i] - 97] == -1)
            alphabet[(int)str[i] - 97] = i;
    for(int i = 0; i < 26; i++)
        printf("%d ", alphabet[i]);

    return 0;
}